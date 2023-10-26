
#ifndef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) id
#endif

#include <augmented_containers/augmented_rb2p.hpp>
#include <augmented_containers_doc/augmented_rb2p_visualization.hpp>
#include <augmented_containers/augmented_rb3p.hpp>
#include <augmented_containers_doc/augmented_rb3p_visualization.hpp>
#include <random>
#include <map>

std::random_device AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(rd); // Will be used to obtain a seed for the random number engine
std::mt19937 AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(gen)(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(rd)()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(distrib)(0, 100);

struct AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t)
{
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) *prev = nullptr, *next = nullptr;
};
struct AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_end_t)
{
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) *front = nullptr, *back = nullptr;
};

struct AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)
{
    struct accumulated_storage_t
    {
        std::map<std::size_t, AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_end_t)> key_and_node_ends;
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t)
        node;
        accumulated_storage_t() = default;
        void take_over(accumulated_storage_t const &other)
        {
            using namespace augmented_containers::detail::language;
            this->key_and_node_ends = other.key_and_node_ends;
            for(std::pair<std::size_t const, AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_end_t)> &key_and_node_end : this->key_and_node_ends)
            {
                tagged_ptr_bit0_unsetted(key_and_node_end.second.front)->prev = reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) *>(tagged_ptr_bit0_setted(&key_and_node_end.second));
                tagged_ptr_bit0_unsetted(key_and_node_end.second.back)->next = reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) *>(tagged_ptr_bit0_setted(&key_and_node_end.second));
            }
        }
        accumulated_storage_t(accumulated_storage_t const &other)
        {
            take_over(other);
        }
        accumulated_storage_t &operator=(accumulated_storage_t const &other) &
        {
            if(this == &other)
                return *this;
            take_over(other);
            return *this;
        }
    };
    static constexpr std::size_t offset_of_node_in_accumulated_storage_t = offsetof(accumulated_storage_t, node);

    accumulated_storage_t identity_element() const { return {}; }
    accumulated_storage_t operator()(accumulated_storage_t &lhs, int const &rhs) const;
    accumulated_storage_t operator()(accumulated_storage_t &lhs, accumulated_storage_t &rhs) const;
};

struct AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_accumulator_t)
    : public augmented_containers::augmented_sequence_helpers::accumulator_wrapping_accumulating_binary_functor_t<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)>
{
    static constexpr bool uses_siblings = true;
};

std::vector<augmented_containers::augmented_sequence_t<
    int,
    std::allocator<int>,
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_accumulator_t),
    std::integral_constant<augmented_containers::augmented_sequence_physical_representation_e, augmented_containers::augmented_sequence_physical_representation_e::AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION>,
    std::integral_constant<augmented_containers::augmented_sequence_size_management_e, augmented_containers::augmented_sequence_size_management_e::AUGMENTED_SEQUENCE_SIZE_MANAGEMENT> //
    > //
    >
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)(2);

std::size_t AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(calculate_group_by_s_key)(decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::element_t const &element) { return (element % 3 + 3) % 3; }
AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::accumulated_storage_t AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::operator()(accumulated_storage_t &lhs, int const &rhs) const
{
    using namespace augmented_containers::detail::language;
    accumulated_storage_t result = lhs;
    decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_rhs = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_element_pointer(const_cast<int *>(&rhs));
    std::size_t group_by_key = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(calculate_group_by_s_key)(rhs);
    if(auto it = result.key_and_node_ends.find(group_by_key); it == result.key_and_node_ends.end())
    {
        it = result.key_and_node_ends.insert({group_by_key, AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_end_t){.front = tagged_ptr_bit0_setted(&iterator_rhs.to_pointer_accumulated_storage()->node), .back = tagged_ptr_bit0_setted(&iterator_rhs.to_pointer_accumulated_storage()->node)}}).first;
        iterator_rhs.to_pointer_accumulated_storage()->node.prev = iterator_rhs.to_pointer_accumulated_storage()->node.next = reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) *>(tagged_ptr_bit0_setted(&it->second));
    }
    else
    {
        tagged_ptr_bit0_unsetted(it->second.back)->next = &iterator_rhs.to_pointer_accumulated_storage()->node;
        iterator_rhs.to_pointer_accumulated_storage()->node.prev = tagged_ptr_bit0_unsetted(it->second.back);
        iterator_rhs.to_pointer_accumulated_storage()->node.next = reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) *>(tagged_ptr_bit0_setted(&it->second));
        it->second.back = tagged_ptr_bit0_setted(&iterator_rhs.to_pointer_accumulated_storage()->node);
    }
    return result;
}
AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::accumulated_storage_t AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::operator()(accumulated_storage_t &lhs, accumulated_storage_t &rhs) const
{
    using namespace augmented_containers::detail::language;
    accumulated_storage_t result = lhs;
    for(std::pair<std::size_t const, AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_end_t)> &key_and_node_end : rhs.key_and_node_ends)
    {
        if(auto it = result.key_and_node_ends.find(key_and_node_end.first); it == result.key_and_node_ends.end())
        {
            it = result.key_and_node_ends.insert(key_and_node_end).first;
            tagged_ptr_bit0_unsetted(it->second.back)->next = tagged_ptr_bit0_unsetted(it->second.front)->prev = reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) *>(tagged_ptr_bit0_setted(&it->second));
        }
        else
        {
            tagged_ptr_bit0_unsetted(it->second.back)->next = tagged_ptr_bit0_unsetted(key_and_node_end.second.front);
            tagged_ptr_bit0_unsetted(key_and_node_end.second.front)->prev = tagged_ptr_bit0_unsetted(it->second.back);
            tagged_ptr_bit0_unsetted(key_and_node_end.second.back)->next = reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) *>(tagged_ptr_bit0_setted(&it->second));
            it->second.back = key_and_node_end.second.back;
        }
    }
    return result;
}

std::vector<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators){
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].begin(),
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].end(),
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].begin(),
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].end(),
};
std::vector<std::size_t> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index){
    0,
    0,
    1,
    1,
};
std::vector<std::size_t> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index)() { return AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index); }
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement)(std::size_t iterator_index) { --AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; }
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment)(std::size_t iterator_index) { ++AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; }
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance)(std::size_t iterator_index, std::ptrdiff_t offset)
{
    [&](auto &augmented_sequence_iterators) // https://stackoverflow.com/questions/47000914/false-branch-of-if-constexpr-not-discarded-in-templated-lambda
    {
        if constexpr(decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::support_random_access)
            augmented_sequence_iterators[iterator_index] += offset;
    }(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators));
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index)(std::size_t iterator_index, std::size_t container_index, std::ptrdiff_t index)
{
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)
    [iterator_index] = std::ranges::next(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[container_index].begin(), index);
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
    [iterator_index] = container_index;
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert)(std::size_t iterator_index)
{
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)
    [iterator_index] = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index]].insert(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index], AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(distrib)(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(gen)));
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase)(std::size_t iterator_index)
{
    if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index]].end())
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_will_be_invalidated;
        std::ranges::transform(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators), std::back_inserter(iterators_will_be_invalidated), [&](decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator)
            { return iterator == AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; });
#else
        std::vector<bool> iterators_will_be_invalidated = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators) | std::views::transform([&](decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator)
                                                                                                                                   { return iterator == AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; }) |
            std::ranges::to<std::vector>();
#endif
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)
        [iterator_index] = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index]].erase(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]);
        std::ranges::for_each(iterators_will_be_invalidated, [&, index = 0](bool iterator_will_be_invalidated) mutable
            {if(iterator_will_be_invalidated)AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[index]=AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index];++index; });
    }
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split)(std::size_t iterator_index)
{
    decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_temp = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index];
    if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 0)
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_will_be_invalidated;
        std::ranges::transform(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index), std::back_inserter(iterators_will_be_invalidated), [&](std::size_t iterator_container_index)
            { return iterator_container_index == 1; });
#else
        std::vector<bool> iterators_will_be_invalidated = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index) | std::views::transform([&](std::size_t iterator_container_index)
                                                                                                                                                   { return iterator_container_index == 1; }) |
            std::ranges::to<std::vector>();
#endif
        while(iterator_temp != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].end())
        {
            for(std::size_t other_iterator_index : std::views::iota(static_cast<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators))::size_type>(0), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size()))
            {
                if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[other_iterator_index] == iterator_temp)
                    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
                [other_iterator_index] = 1;
            }
            ++iterator_temp;
        }
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
        [1] = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].split_emit_right(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]);
        std::ranges::for_each(iterators_will_be_invalidated, [&, index = 0](bool iterator_will_be_invalidated) mutable
            {if(iterator_will_be_invalidated)AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[index]=AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].end();++index; });
    }
    else if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 1)
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_will_be_invalidated;
        std::ranges::transform(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index), std::back_inserter(iterators_will_be_invalidated), [&](std::size_t iterator_container_index)
            { return iterator_container_index == 0; });
#else
        std::vector<bool> iterators_will_be_invalidated = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index) | std::views::transform([&](std::size_t iterator_container_index)
                                                                                                                                                   { return iterator_container_index == 0; }) |
            std::ranges::to<std::vector>();
#endif
        if(iterator_temp != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].begin())
        {
            --iterator_temp;
            while(iterator_temp != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].begin())
            {
                for(std::size_t other_iterator_index : std::views::iota(static_cast<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators))::size_type>(0), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size()))
                {
                    if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[other_iterator_index] == iterator_temp)
                        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
                    [other_iterator_index] = 0;
                }
                --iterator_temp;
            }
            for(std::size_t other_iterator_index : std::views::iota(static_cast<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators))::size_type>(0), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size()))
            {
                if(other_iterator_index != iterator_index && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[other_iterator_index] == iterator_temp)
                    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
                [other_iterator_index] = 0;
            }
        }
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
        [0] = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].split_emit_left(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]);
        std::ranges::for_each(iterators_will_be_invalidated, [&, index = 0](bool iterator_will_be_invalidated) mutable
            {if(iterator_will_be_invalidated)AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[index]=AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].end();++index; });
    }
    else std::unreachable();
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat)(std::size_t container_index)
{
    if(container_index == 0)
    {
        for(std::size_t iterator_index = 0; iterator_index != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size(); ++iterator_index)
        {
            if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 1 && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].end())
                AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
            [iterator_index] = 0;
        }
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
        [0] << std::move(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1]);
    }
    else if(container_index == 1)
    {
        for(std::size_t iterator_index = 0; iterator_index != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size(); ++iterator_index)
        {
            if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 0 && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].end())
                AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
            [iterator_index] = 1;
        }
        std::move(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0]) >> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1];
    }
    else std::unreachable();
}

void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output)(std::size_t iterator_index, std::string value)
{
    if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index]].end())
        *AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] = [value]()
        {int value_int;std::istringstream(value)>>value_int;return value_int; }();
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range)(std::size_t container_index)
{
    if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[2 * container_index + 0] == container_index && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[2 * container_index + 1] == container_index &&
        std::ranges::distance(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[container_index].begin(), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 0]) <= std::ranges::distance(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[container_index].begin(), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 1]))
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
    [container_index].update_range(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 0], AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 1]);
}

std::vector<std::string> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string)()
{
    std::vector<std::string> result;
    using namespace dot;
    using namespace augmented_containers::detail::visualization::AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(augmented_sequence_);

    for(dot::graph_t &graph : to_graphs(
            AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s),
            to_graphs_parameters_t{
#ifndef __EMSCRIPTEN__
                .element_to_string_converter =
#endif
                    [](auto parameters) -> html_label_t
                { return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << parameters.datum).str().data()))}}}}; },
#ifndef __EMSCRIPTEN__
               .accumulated_storage_to_string_converter =
#endif
                    [](auto parameters) -> html_label_t
                {
                    using namespace augmented_containers::detail::language;
                    using namespace augmented_containers::detail::visualization;
                    using element_t = typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::element_t;
                    using accumulated_storage_t = typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::accumulated_storage_t;

                    decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_from = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_accumulated_storage_pointer(&const_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::accumulated_storage_t &>(parameters.datum));
                    std::u8string color_primary = std::map<std::size_t, std::u8string>{{0, u8"#FF0000"}, {1, u8"#00FF00"}, {2, u8"#0000FF"}}.at(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(calculate_group_by_s_key)(*iterator_from));
                    decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_root = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t{[&]()
                        {
                            if constexpr(static_cast<augmented_containers::augmented_sequence_physical_representation_e>(typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::augmented_sequence_physical_representation_t{}) == augmented_containers::augmented_sequence_physical_representation_e::rb3p)
                                return tagged_ptr_bit0_unsetted(tagged_ptr_bit0_unsetted(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[parameters.container_index].node_end)->parent());
                            else if constexpr(static_cast<augmented_containers::augmented_sequence_physical_representation_e>(typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::augmented_sequence_physical_representation_t{}) == augmented_containers::augmented_sequence_physical_representation_e::rb2p)
                                return tagged_ptr_bit0_unsetted(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[parameters.container_index].node_end->parent_all());
                            else std::unreachable();
                        }()};
                    for(std::pair<std::size_t const, AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_end_t)> const &key_and_node_end : parameters.datum.key_and_node_ends)
                    {
                        std::u8string color_primary = std::map<std::size_t, std::u8string>{{0, u8"#FF0000"}, {1, u8"#00FF00"}, {2, u8"#0000FF"}}.at(key_and_node_end.first);
                        std::u8string color_secondary = std::map<std::size_t, std::u8string>{{0, u8"#AA0000"}, {1, u8"#00AA00"}, {2, u8"#0000AA"}}.at(key_and_node_end.first);
                        if(true //
                            //                       && iterator_from == iterator_root //
                        )
                        {
                            if(key_and_node_end.second.front != tagged_ptr_bit0_setted(&parameters.datum.node))
                            {
                                decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_accumulated_storage_pointer(reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::accumulated_storage_t *>(const_cast<std::byte *>(reinterpret_cast<std::byte const *>(tagged_ptr_bit0_unsetted(key_and_node_end.second.front)) - AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::offset_of_node_in_accumulated_storage_t)));
                                parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                    {{
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_from.current_node), u8"accumulated_storage.node_end_" + object_pointer_to_string(&key_and_node_end.second) + u8".front", c},
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"accumulated_storage.node.prev", c},
                                    }},
                                    {{
                                        {u8"id", u8"tree_node_" + object_pointer_to_string(iterator_from.current_node) + u8"->accumulated_storage.node_end_" + object_pointer_to_string(&key_and_node_end.second) + u8".front"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                        {u8"headclip", u8"false"},
                                        {u8"color", iterator_from == iterator_root ? color_primary : color_secondary},
                                        {u8"style", u8"dashed"},
                                    }}};
                            }
                        }
                        if(true //
                            //                       && iterator_from == iterator_root //
                        )
                        {
                            if(key_and_node_end.second.back != tagged_ptr_bit0_setted(&parameters.datum.node))
                            {
                                decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_accumulated_storage_pointer(reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::accumulated_storage_t *>(const_cast<std::byte *>(reinterpret_cast<std::byte const *>(tagged_ptr_bit0_unsetted(key_and_node_end.second.back)) - AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::offset_of_node_in_accumulated_storage_t)));
                                parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                    {{
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_from.current_node), u8"accumulated_storage.node_end_" + object_pointer_to_string(&key_and_node_end.second) + u8".back", c},
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"accumulated_storage.node.next", c},
                                    }},
                                    {{
                                        {u8"id", u8"tree_node_" + object_pointer_to_string(iterator_from.current_node) + u8"->accumulated_storage.node_end_" + object_pointer_to_string(&key_and_node_end.second) + u8".back"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                        {u8"headclip", u8"false"},
                                        {u8"color", iterator_from == iterator_root ? color_primary : color_secondary},
                                        {u8"style", u8"dashed"},
                                    }}};
                            }
                        }
                    }

                    if(parameters.datum.node.prev != nullptr)
                    {
                        if(tagged_ptr_bit0_is_setted(parameters.datum.node.prev))
                        {
                            if(std::ranges::none_of(parameters.datum.key_and_node_ends, [&](std::pair<std::size_t const, AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_end_t)> const &key_and_node_end)
                                   { return parameters.datum.node.prev == reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) const *>(tagged_ptr_bit0_setted(&key_and_node_end.second)); }))
                            {
                                decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = iterator_root;
                                parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                    {{
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_from.current_node), u8"accumulated_storage.node.prev", c},
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"accumulated_storage.node_end_" + object_pointer_to_string(tagged_ptr_bit0_unsetted(parameters.datum.node.prev)) + u8".front", c},
                                    }},
                                    {{
                                        {u8"id", u8"tree_node_" + object_pointer_to_string(iterator_from.current_node) + u8"->accumulated_storage.node.prev"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                        {u8"headclip", u8"false"},
                                        {u8"color", color_primary},
                                        {u8"style", u8"dashed"},
                                    }}};
                            }
                        }
                        else
                        {
                            decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_accumulated_storage_pointer(reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::accumulated_storage_t *>(const_cast<std::byte *>(reinterpret_cast<std::byte const *>(parameters.datum.node.prev) - AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::offset_of_node_in_accumulated_storage_t)));
                            parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                {{
                                    node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_from.current_node), u8"accumulated_storage.node.prev", c},
                                    node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"accumulated_storage.node.next", c},
                                }},
                                {{
                                    {u8"id", u8"tree_node_" + object_pointer_to_string(iterator_from.current_node) + u8"->accumulated_storage.node.prev"},
                                    {u8"constraint", u8"false"},
                                    {u8"tailclip", u8"false"},
                                    {u8"headclip", u8"false"},
                                    {u8"color", color_primary},
                                }}};
                        }
                    }
                    if(parameters.datum.node.next != nullptr)
                    {
                        if(tagged_ptr_bit0_is_setted(parameters.datum.node.next))
                        {
                            if(std::ranges::none_of(parameters.datum.key_and_node_ends, [&](std::pair<std::size_t const, AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_end_t)> const &key_and_node_end)
                                   { return parameters.datum.node.next == reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) const *>(tagged_ptr_bit0_setted(&key_and_node_end.second)); }))
                            {
                                decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = iterator_root;
                                parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                    {{
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_from.current_node), u8"accumulated_storage.node.next", c},
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"accumulated_storage.node_end_" + object_pointer_to_string(tagged_ptr_bit0_unsetted(parameters.datum.node.next)) + u8".back", c},
                                    }},
                                    {{
                                        {u8"id", u8"tree_node_" + object_pointer_to_string(iterator_from.current_node) + u8"->accumulated_storage.node.next"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                        {u8"headclip", u8"false"},
                                        {u8"color", color_primary},
                                        {u8"style", u8"dashed"},
                                    }}};
                            }
                        }
                        else
                        {
                            decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_accumulated_storage_pointer(reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::accumulated_storage_t *>(const_cast<std::byte *>(reinterpret_cast<std::byte const *>(parameters.datum.node.next) - AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_group_by_element_binary_functor_t)::offset_of_node_in_accumulated_storage_t)));
                            parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                {{
                                    node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_from.current_node), u8"accumulated_storage.node.next", c},
                                    node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"accumulated_storage.node.prev", c},
                                }},
                                {{
                                    {u8"id", u8"tree_node_" + object_pointer_to_string(iterator_from.current_node) + u8"->accumulated_storage.node.next"},
                                    {u8"constraint", u8"false"},
                                    {u8"tailclip", u8"false"},
                                    {u8"headclip", u8"false"},
                                    {u8"color", color_primary},
                                }}};
                        }
                    }
                    decltype(table_t::rows) result_C1001_node_ends;
                    for(std::pair<std::size_t const, AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_end_t)> const &key_and_node_end : parameters.datum.key_and_node_ends)
                    {
                        std::u8string color_primary = std::map<std::size_t, std::u8string>{{0, u8"#FF0000"}, {1, u8"#00FF00"}, {2, u8"#0000FF"}}.at(key_and_node_end.first);
                        std::u8string color_secondary = std::map<std::size_t, std::u8string>{{0, u8"#AA0000"}, {1, u8"#00AA00"}, {2, u8"#0000AA"}}.at(key_and_node_end.first);
                        text_t text_C1001_node_end_front{{textitem_t{std::make_pair(font_t{.COLOR = iterator_from == iterator_root ? color_primary : color_secondary}, text_t{{textitem_t{key_and_node_end.second.front == tagged_ptr_bit0_setted(&parameters.datum.node) ? u8"↓" : u8" "}}})}}};
                        text_t text_C1001_node_end_back{{textitem_t{std::make_pair(font_t{.COLOR = iterator_from == iterator_root ? color_primary : color_secondary}, text_t{{textitem_t{key_and_node_end.second.back == tagged_ptr_bit0_setted(&parameters.datum.node) ? u8"↓" : u8" "}}})}}};
                        decltype(table_t::rows) row_C1001{
                            row_t{{
                                cell_t{
                                    .PORT = u8"accumulated_storage.node_end_" + object_pointer_to_string(&key_and_node_end.second) + u8".front",
                                    .content = html_label_t{text_C1001_node_end_front},
                                },
                                cell_t{
                                    .PORT = u8"accumulated_storage.node_end_" + object_pointer_to_string(&key_and_node_end.second) + u8".back",
                                    .content = html_label_t{text_C1001_node_end_back},
                                },
                            }},
                        };
                        result_C1001_node_ends.push_back(row_t{{
                            cell_t{
                                .content = html_label_t{text_t{{{index_to_string(key_and_node_end.first)}}}},
                            },
                            cell_t{
                                .content = html_label_t{fonttable_t{table_t{
                                    .BORDER = 0,
                                    .CELLBORDER = 1,
                                    .CELLSPACING = 0,
                                    .PORT = u8"accumulated_storage_" + object_pointer_to_string(&key_and_node_end.second),
                                    .rows = row_C1001,
                                }}},
                            },
                        }});
                    }
                    text_t text_C1001_node_prev{{textitem_t{std::make_pair(font_t{.COLOR = color_primary}, text_t{{textitem_t{std::ranges::any_of(parameters.datum.key_and_node_ends, [&](std::pair<std::size_t const, AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_end_t)> const &key_and_node_end)
                                                                                                                                  { return parameters.datum.node.prev == reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) const *>(tagged_ptr_bit0_setted(&key_and_node_end.second)); })
                                                                                                                   ? u8"↑"
                                                                                                                   : u8" "}}})}}};
                    text_t text_C1001_node_next{{textitem_t{std::make_pair(font_t{.COLOR = color_primary}, text_t{{textitem_t{std::ranges::any_of(parameters.datum.key_and_node_ends, [&](std::pair<std::size_t const, AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_end_t)> const &key_and_node_end)
                                                                                                                                  { return parameters.datum.node.next == reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(group_by_element_node_t) const *>(tagged_ptr_bit0_setted(&key_and_node_end.second)); })
                                                                                                                   ? u8"↑"
                                                                                                                   : u8" "}}})}}};
                    decltype(table_t::rows) result_C1001_node{
                        row_t{{
                            cell_t{
                                .BGCOLOR = parameters.datum.node.prev == nullptr ? inactive_cell_color : active_cell_color,
                                .PORT = u8"accumulated_storage.node.prev",
                                .content = html_label_t{text_C1001_node_prev},
                            },
                            cell_t{
                                .BGCOLOR = parameters.datum.node.next == nullptr ? inactive_cell_color : active_cell_color,
                                .PORT = u8"accumulated_storage.node.next",
                                .content = html_label_t{text_C1001_node_next},
                            },
                        }},
                    };
                    return html_label_t{fonttable_t{table_t{
                        .BORDER = 0,
                        .CELLBORDER = 1,
                        .CELLSPACING = 0,
                        .PORT = u8"accumulated_storage",
                        .rows = [&]()
                        {
                            return decltype(table_t::rows){
                                row_t{{cell_t{
                                    .content = html_label_t{fonttable_t{table_t{
                                        .BORDER = 0,
                                        .CELLBORDER = 1,
                                        .CELLSPACING = 0,
                                        .PORT = u8"accumulated_storage.key_and_node_ends",
                                        .rows = result_C1001_node_ends,
                                    }}},
                                }}},
                                row_t{{cell_t{
                                    .content = html_label_t{fonttable_t{table_t{
                                        .BORDER = 0,
                                        .CELLBORDER = 1,
                                        .CELLSPACING = 0,
                                        .PORT = u8"accumulated_storage.node",
                                        .rows = result_C1001_node,
                                    }}},
                                }}},
                            };
                        }(),
                    }}};
                },
#ifndef __EMSCRIPTEN__
               .iterators =
#endif
                    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators),
#ifndef __EMSCRIPTEN__
               .iterators_container_index =
#endif
                    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index),
#ifndef __EMSCRIPTEN__
               .read_range =
#endif
                    false,
            }))
    {
        result.push_back((std::ostringstream() << graph).str());
    }
    return result;
}
