
#ifndef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) id
#endif

#include <augmented_containers/augmented_rb2p.hpp>
#include <augmented_containers_doc/augmented_rb2p_visualization.hpp>
#include <augmented_containers/augmented_rb3p.hpp>
#include <augmented_containers_doc/augmented_rb3p_visualization.hpp>
#include <random>

std::random_device AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(rd); // Will be used to obtain a seed for the random number engine
std::mt19937 AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(gen)(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(rd)()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(distrib)(0, 100);

struct AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t)
{
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t) *prev = nullptr, *next = nullptr;
};
struct AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_end_t)
{
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t) *front = nullptr, *back = nullptr;
};

struct AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)
{
    struct accumulated_storage_t
    {
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_end_t)
        node_end;
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t)
        node;
        accumulated_storage_t() = default;
        void take_over(accumulated_storage_t const &other)
        {
            using namespace augmented_containers::detail::language;
            assert((other.node_end.front == nullptr) == (other.node_end.back == nullptr));
            this->node_end = other.node_end;
            if(this->node_end.front != nullptr)
            {
                tagged_ptr_bit0_unsetted(this->node_end.front)->prev = reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t) *>(tagged_ptr_bit0_setted(&this->node_end));
                tagged_ptr_bit0_unsetted(this->node_end.back)->next = reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t) *>(tagged_ptr_bit0_setted(&this->node_end));
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

struct AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_accumulator_t)
    : public augmented_containers::augmented_sequence_helpers::accumulator_wrapping_accumulating_binary_functor_t<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)>
{
    static constexpr bool uses_siblings = true;
};

std::vector<augmented_containers::augmented_sequence_t<
    int,
    std::allocator<int>,
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_accumulator_t),
    std::integral_constant<augmented_containers::augmented_sequence_physical_representation_e, augmented_containers::augmented_sequence_physical_representation_e::AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION>,
    std::integral_constant<augmented_containers::augmented_sequence_size_management_e, augmented_containers::augmented_sequence_size_management_e::AUGMENTED_SEQUENCE_SIZE_MANAGEMENT> //
    > //
    >
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)(2);

bool AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(is_front_of_chunk)(decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator)
{
    if(auto iterator_prev = std::ranges::prev(iterator); iterator_prev.is_end())
        return true;
    else
        return (*iterator_prev < 50) != (*iterator < 50);
}
AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::accumulated_storage_t AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::operator()(accumulated_storage_t &lhs, int const &rhs) const
{
    using namespace augmented_containers::detail::language;
    accumulated_storage_t result = lhs;
    decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_rhs = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_element_pointer(const_cast<int *>(&rhs));
    if(!AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(is_front_of_chunk)(iterator_rhs))
        iterator_rhs.to_pointer_accumulated_storage()->node.prev = iterator_rhs.to_pointer_accumulated_storage()->node.next = nullptr;
    else
    {
        if(result.node_end.front == nullptr && result.node_end.back == nullptr)
        {
            iterator_rhs.to_pointer_accumulated_storage()->node.prev = iterator_rhs.to_pointer_accumulated_storage()->node.next = reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t) *>(tagged_ptr_bit0_setted(&result.node_end));
            result.node_end.front = result.node_end.back = tagged_ptr_bit0_setted(&iterator_rhs.to_pointer_accumulated_storage()->node);
        }
        else if(result.node_end.front != nullptr && result.node_end.back != nullptr)
        {
            tagged_ptr_bit0_unsetted(result.node_end.back)->next = &iterator_rhs.to_pointer_accumulated_storage()->node;
            iterator_rhs.to_pointer_accumulated_storage()->node.prev = tagged_ptr_bit0_unsetted(result.node_end.back);
            iterator_rhs.to_pointer_accumulated_storage()->node.next = reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t) *>(tagged_ptr_bit0_setted(&result.node_end));
            result.node_end.back = tagged_ptr_bit0_setted(&iterator_rhs.to_pointer_accumulated_storage()->node);
        }
        else std::unreachable();
    }
    return result;
}
AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::accumulated_storage_t AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::operator()(accumulated_storage_t &lhs, accumulated_storage_t &rhs) const
{
    using namespace augmented_containers::detail::language;
    if(lhs.node_end.front == nullptr && lhs.node_end.back == nullptr)
    {
        if(rhs.node_end.front == nullptr && rhs.node_end.back == nullptr)
            return {};
        else if(rhs.node_end.front != nullptr && rhs.node_end.back != nullptr)
            return rhs;
        else std::unreachable();
    }
    else if(lhs.node_end.front != nullptr && lhs.node_end.back != nullptr)
    {
        if(rhs.node_end.front == nullptr && rhs.node_end.back == nullptr)
            return lhs;
        else if(rhs.node_end.front != nullptr && rhs.node_end.back != nullptr)
        {
            accumulated_storage_t result = lhs;
            tagged_ptr_bit0_unsetted(result.node_end.back)->next = tagged_ptr_bit0_unsetted(rhs.node_end.front);
            tagged_ptr_bit0_unsetted(rhs.node_end.front)->prev = tagged_ptr_bit0_unsetted(result.node_end.back);
            tagged_ptr_bit0_unsetted(rhs.node_end.back)->next = reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t) *>(tagged_ptr_bit0_setted(&result.node_end));
            result.node_end.back = rhs.node_end.back;
            return result;
        }
        else std::unreachable();
    }
    else std::unreachable();
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
                    using element_t [[maybe_unused]] = typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::element_t;
                    using accumulated_storage_t [[maybe_unused]] = typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::accumulated_storage_t;

                    decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_from = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_accumulated_storage_pointer(&const_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::accumulated_storage_t &>(parameters.datum));
                    decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_root = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t{[&]()
                        {
                            if constexpr(static_cast<augmented_containers::augmented_sequence_physical_representation_e>(typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::augmented_sequence_physical_representation_t{}) == augmented_containers::augmented_sequence_physical_representation_e::rb3p)
                                return tagged_ptr_bit0_unsetted(tagged_ptr_bit0_unsetted(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[parameters.container_index].node_end)->parent());
                            else if constexpr(static_cast<augmented_containers::augmented_sequence_physical_representation_e>(typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::augmented_sequence_physical_representation_t{}) == augmented_containers::augmented_sequence_physical_representation_e::rb2p)
                                return tagged_ptr_bit0_unsetted(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[parameters.container_index].node_end->parent_all());
                            else std::unreachable();
                        }()};
                    if(parameters.datum.node_end.front != nullptr //
                        //                       && iterator_from == iterator_root //
                    )
                    {
                        if(parameters.datum.node_end.front != tagged_ptr_bit0_setted(&parameters.datum.node))
                        {
                            decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_accumulated_storage_pointer(reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::accumulated_storage_t *>(const_cast<std::byte *>(reinterpret_cast<std::byte const *>(tagged_ptr_bit0_unsetted(parameters.datum.node_end.front)) - AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::offset_of_node_in_accumulated_storage_t)));
                            parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                {{
                                    node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_from.current_node), u8"accumulated_storage.node_end.front", c},
                                    node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"accumulated_storage.node.prev", c},
                                }},
                                {{
                                    {u8"id", u8"tree_node_" + object_pointer_to_string(iterator_from.current_node) + u8"->accumulated_storage.node_end.front"},
                                    {u8"constraint", u8"false"},
                                    {u8"tailclip", u8"false"},
                                    {u8"headclip", u8"false"},
                                    {u8"color", iterator_from == iterator_root ? u8"#0000FF" : u8"#00B4B4"},
                                    {u8"style", u8"dashed"},
                                }}};
                        }
                    }
                    if(parameters.datum.node_end.back != nullptr //
                        //                       && iterator_from == iterator_root //
                    )
                    {
                        if(parameters.datum.node_end.back != tagged_ptr_bit0_setted(&parameters.datum.node))
                        {
                            decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_accumulated_storage_pointer(reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::accumulated_storage_t *>(const_cast<std::byte *>(reinterpret_cast<std::byte const *>(tagged_ptr_bit0_unsetted(parameters.datum.node_end.back)) - AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::offset_of_node_in_accumulated_storage_t)));
                            parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                {{
                                    node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_from.current_node), u8"accumulated_storage.node_end.back", c},
                                    node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"accumulated_storage.node.next", c},
                                }},
                                {{
                                    {u8"id", u8"tree_node_" + object_pointer_to_string(iterator_from.current_node) + u8"->accumulated_storage.node_end.back"},
                                    {u8"constraint", u8"false"},
                                    {u8"tailclip", u8"false"},
                                    {u8"headclip", u8"false"},
                                    {u8"color", iterator_from == iterator_root ? u8"#0000FF" : u8"#00B4B4"},
                                    {u8"style", u8"dashed"},
                                }}};
                        }
                    }

                    if(parameters.datum.node.prev != nullptr)
                    {
                        if(tagged_ptr_bit0_is_setted(parameters.datum.node.prev))
                        {
                            if(parameters.datum.node.prev != reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t) const *>(tagged_ptr_bit0_setted(&parameters.datum.node_end)))
                            {
                                decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = iterator_root;
                                parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                    {{
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_from.current_node), u8"accumulated_storage.node.prev", c},
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"accumulated_storage.node_end.front", c},
                                    }},
                                    {{
                                        {u8"id", u8"tree_node_" + object_pointer_to_string(iterator_from.current_node) + u8"->accumulated_storage.node.prev"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                        {u8"headclip", u8"false"},
                                        {u8"color", u8"#0000FF"},
                                        {u8"style", u8"dashed"},
                                    }}};
                            }
                        }
                        else
                        {
                            decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_accumulated_storage_pointer(reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::accumulated_storage_t *>(const_cast<std::byte *>(reinterpret_cast<std::byte const *>(parameters.datum.node.prev) - AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::offset_of_node_in_accumulated_storage_t)));
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
                                    {u8"color", u8"#0000FF"},
                                }}};
                        }
                    }
                    if(parameters.datum.node.next != nullptr)
                    {
                        if(tagged_ptr_bit0_is_setted(parameters.datum.node.next))
                        {
                            if(parameters.datum.node.next != reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t) const *>(tagged_ptr_bit0_setted(&parameters.datum.node_end)))
                            {
                                decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = iterator_root;
                                parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                    {{
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_from.current_node), u8"accumulated_storage.node.next", c},
                                        node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"accumulated_storage.node_end.back", c},
                                    }},
                                    {{
                                        {u8"id", u8"tree_node_" + object_pointer_to_string(iterator_from.current_node) + u8"->accumulated_storage.node.next"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                        {u8"headclip", u8"false"},
                                        {u8"color", u8"#0000FF"},
                                        {u8"style", u8"dashed"},
                                    }}};
                            }
                        }
                        else
                        {
                            decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_accumulated_storage_pointer(reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::accumulated_storage_t *>(const_cast<std::byte *>(reinterpret_cast<std::byte const *>(parameters.datum.node.next) - AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::offset_of_node_in_accumulated_storage_t)));
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
                                    {u8"color", u8"#0000FF"},
                                }}};
                        }
                    }
                    text_t text_C1001_node_end_front{{textitem_t{std::make_pair(font_t{.COLOR = iterator_from == iterator_root ? u8"#0000FF" : u8"#00B4B4"}, text_t{{textitem_t{parameters.datum.node_end.front == tagged_ptr_bit0_setted(&parameters.datum.node) ? u8"↓" : u8" "}}})}}};
                    text_t text_C1001_node_end_back{{textitem_t{std::make_pair(font_t{.COLOR = iterator_from == iterator_root ? u8"#0000FF" : u8"#00B4B4"}, text_t{{textitem_t{parameters.datum.node_end.back == tagged_ptr_bit0_setted(&parameters.datum.node) ? u8"↓" : u8" "}}})}}};
                    decltype(table_t::rows) result_C1001_node_end{
                        row_t{{
                            cell_t{
                                .BGCOLOR = parameters.datum.node_end.front == nullptr ? inactive_cell_color : active_cell_color,
                                .PORT = u8"accumulated_storage.node_end.front",
                                .content = html_label_t{text_C1001_node_end_front},
                            },
                            cell_t{
                                .BGCOLOR = parameters.datum.node_end.back == nullptr ? inactive_cell_color : active_cell_color,
                                .PORT = u8"accumulated_storage.node_end.back",
                                .content = html_label_t{text_C1001_node_end_back},
                            },
                        }},
                    };
                    text_t text_C1001_node_prev{{textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF"}, text_t{{textitem_t{parameters.datum.node.prev == reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t) const *>(tagged_ptr_bit0_setted(&parameters.datum.node_end)) ? u8"↑" : u8" "}}})}}};
                    text_t text_C1001_node_next{{textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF"}, text_t{{textitem_t{parameters.datum.node.next == reinterpret_cast<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(diffing_adjacent_element_node_t) const *>(tagged_ptr_bit0_setted(&parameters.datum.node_end)) ? u8"↑" : u8" "}}})}}};
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
                                        .PORT = u8"accumulated_storage.node_end",
                                        .rows = result_C1001_node_end,
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
