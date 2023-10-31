
#ifndef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) id
#endif

#include <augmented_containers/augmented_rb2p.hpp>
#include <augmented_containers/augmented_rb3p.hpp>
#include <augmented_containers_doc/augmented_rb2p_visualization.hpp>
#include <augmented_containers_doc/augmented_rb3p_visualization.hpp>

#include <array>
#include <random>

std::random_device AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(rd); // Will be used to obtain a seed for the random number engine
std::mt19937 AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(gen)(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(rd)()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(distrib)(0, 10);

template<typename element_t, std::size_t N, bool reverse = false>
struct AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_min_n_element_binary_functor_t)
{
    using accumulated_storage_t = std::array<element_t *, N>;

    accumulated_storage_t identity_element() const { return {}; }
    accumulated_storage_t operator()(accumulated_storage_t &lhs, accumulated_storage_t &rhs) const
    {
        accumulated_storage_t result{};
        auto in1 = lhs.begin(), in1_end = lhs.end(), in2 = rhs.begin(), in2_end = rhs.end();
        auto out = result.begin(), out_end = result.end();
        while (in1 != in1_end && *in1 != nullptr && in2 != in2_end && *in2 != nullptr && out != out_end)
        {
            if ([&]() {
                if constexpr (!reverse)
                  return (**in1 <=> **in2) != std::strong_ordering::greater;
                else
                  return !((**in1 <=> **in2) != std::strong_ordering::greater); }())
                *out++ = *in1++;
            else
                *out++ = *in2++;
        }
        while (in1 != in1_end && *in1 != nullptr && out != out_end)
            *out++ = *in1++;
        while (in2 != in2_end && *in2 != nullptr && out != out_end)
            *out++ = *in2++;
        return result;
    }
    accumulated_storage_t operator()(accumulated_storage_t &lhs, element_t const &rhs) const
    {
        accumulated_storage_t rhs_as_array_of_pointer{{const_cast<element_t *>(&rhs)}};
        return operator()(lhs, rhs_as_array_of_pointer);
    }
};

std::vector<
    augmented_containers::augmented_sequence_t<
        int,
        std::allocator<int>,
        augmented_containers::augmented_sequence_helpers::accumulator_wrapping_accumulating_binary_functor_t<AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(accumulating_min_n_element_binary_functor_t) < int, 3, true>>,
    std::integral_constant<augmented_containers::augmented_sequence_physical_representation_e, augmented_containers::augmented_sequence_physical_representation_e::AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION>,
    std::integral_constant<augmented_containers::augmented_sequence_size_management_e, augmented_containers::augmented_sequence_size_management_e::AUGMENTED_SEQUENCE_SIZE_MANAGEMENT> //
    > //
    >
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)(2);
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
        if constexpr (decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::support_random_access)
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
    if (AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index]].end())
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_will_be_invalidated;
        std::ranges::transform(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators), std::back_inserter(iterators_will_be_invalidated), [&](decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator) { return iterator == AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; });
#else
        std::vector<bool> iterators_will_be_invalidated = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators) | std::views::transform([&](decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator) { return iterator == AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; }) |
            std::ranges::to<std::vector>();
#endif
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)
        [iterator_index] = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index]].erase(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]);
        std::ranges::for_each(iterators_will_be_invalidated, [&, index = 0](bool iterator_will_be_invalidated) mutable {if(iterator_will_be_invalidated)AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[index]=AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index];++index; });
    }
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split)(std::size_t iterator_index)
{
    decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_temp = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index];
    if (AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 0)
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_will_be_invalidated;
        std::ranges::transform(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index), std::back_inserter(iterators_will_be_invalidated), [&](std::size_t iterator_container_index) { return iterator_container_index == 1; });
#else
        std::vector<bool> iterators_will_be_invalidated = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index) | std::views::transform([&](std::size_t iterator_container_index) { return iterator_container_index == 1; }) |
            std::ranges::to<std::vector>();
#endif
        while (iterator_temp != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].end())
        {
            for (std::size_t other_iterator_index : std::views::iota(static_cast<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators))::size_type>(0), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size()))
            {
                if (AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[other_iterator_index] == iterator_temp)
                    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
                [other_iterator_index] = 1;
            }
            ++iterator_temp;
        }
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
        [1] = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].split_emit_right(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]);
        std::ranges::for_each(iterators_will_be_invalidated, [&, index = 0](bool iterator_will_be_invalidated) mutable {if(iterator_will_be_invalidated)AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[index]=AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].end();++index; });
    }
    else if (AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 1)
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_will_be_invalidated;
        std::ranges::transform(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index), std::back_inserter(iterators_will_be_invalidated), [&](std::size_t iterator_container_index) { return iterator_container_index == 0; });
#else
        std::vector<bool> iterators_will_be_invalidated = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index) | std::views::transform([&](std::size_t iterator_container_index) { return iterator_container_index == 0; }) |
            std::ranges::to<std::vector>();
#endif
        if (iterator_temp != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].begin())
        {
            --iterator_temp;
            while (iterator_temp != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].begin())
            {
                for (std::size_t other_iterator_index : std::views::iota(static_cast<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators))::size_type>(0), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size()))
                {
                    if (AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[other_iterator_index] == iterator_temp)
                        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
                    [other_iterator_index] = 0;
                }
                --iterator_temp;
            }
            for (std::size_t other_iterator_index : std::views::iota(static_cast<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators))::size_type>(0), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size()))
            {
                if (other_iterator_index != iterator_index && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[other_iterator_index] == iterator_temp)
                    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
                [other_iterator_index] = 0;
            }
        }
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
        [0] = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].split_emit_left(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]);
        std::ranges::for_each(iterators_will_be_invalidated, [&, index = 0](bool iterator_will_be_invalidated) mutable {if(iterator_will_be_invalidated)AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[index]=AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].end();++index; });
    }
    else std::unreachable();
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat)(std::size_t container_index)
{
    if (container_index == 0)
    {
        for (std::size_t iterator_index = 0; iterator_index != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size(); ++iterator_index)
        {
            if (AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 1 && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].end())
                AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
            [iterator_index] = 0;
        }
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
        [0] << std::move(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1]);
    }
    else if (container_index == 1)
    {
        for (std::size_t iterator_index = 0; iterator_index != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size(); ++iterator_index)
        {
            if (AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 0 && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].end())
                AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
            [iterator_index] = 1;
        }
        std::move(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0]) >> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1];
    }
    else std::unreachable();
}

void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output)(std::size_t iterator_index, std::string value)
{
    if (AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index]].end())
        *AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] = [value]() {int value_int;std::istringstream(value)>>value_int;return value_int; }();
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range)(std::size_t container_index)
{
    if (AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[2 * container_index + 0] == container_index && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[2 * container_index + 1] == container_index &&
        std::ranges::distance(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[container_index].begin(), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 0]) <= std::ranges::distance(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[container_index].begin(), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 1]))
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
    [container_index].update_range(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 0], AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 1]);
}

std::vector<std::string> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string)()
{
    std::vector<std::string> result;
    using namespace dot;
    using namespace augmented_containers::detail::visualization::AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(augmented_sequence_);

    for (dot::graph_t &graph : to_graphs(
             AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s),
             to_graphs_parameters_t{
                 .element_to_string_converter = [](auto parameters) -> html_label_t {
                     return html_label_t{fonttable_t{table_t{
                         .BORDER = 0,
                         .CELLBORDER = 1,
                         .CELLSPACING = 0,
                         .PORT = u8"element",
                         .rows = [&]() {
                             return decltype(table_t::rows){
                                 row_t{{cell_t{
                                     .content = html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << parameters.datum).str().data()))}}}},
                                 }}},
                             };
                         }(),
                     }}};
                 },
                .accumulated_storage_to_string_converter = [](auto parameters) -> html_label_t {
                    using namespace augmented_containers::detail::language;
                    using namespace augmented_containers::detail::visualization;
                    using element_t = typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::element_t;
                    using accumulated_storage_t = typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::accumulated_storage_t;
                    switch(parameters.accumulated_storage_node_type)
                    {
                    case accumulated_storage_node_type_e::uninitialized: std::unreachable(); break;
                    case accumulated_storage_node_type_e::tree_node:
                    {
                        decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_from = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_accumulated_storage_pointer(&const_cast<accumulated_storage_t &>(parameters.datum));
                        decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_root = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t{[&]()
                            {
                                if constexpr(static_cast<augmented_containers::augmented_sequence_physical_representation_e>(typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::augmented_sequence_physical_representation_t{}) == augmented_containers::augmented_sequence_physical_representation_e::rb3p)
                                    return tagged_ptr_bit0_unsetted(tagged_ptr_bit0_unsetted(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[parameters.container_index].node_end)->parent());
                                else if constexpr(static_cast<augmented_containers::augmented_sequence_physical_representation_e>(typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::augmented_sequence_physical_representation_t{}) == augmented_containers::augmented_sequence_physical_representation_e::rb2p)
                                    return tagged_ptr_bit0_unsetted(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[parameters.container_index].node_end->parent_all());
                                else std::unreachable();
                            }()};
                        for(element_t * const &p : parameters.datum)
                        {
                            if(p != nullptr)
                            {
                                decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_element_pointer(const_cast<element_t *>(p));
                                if(iterator_from != iterator_to)

                                    parameters.converter_generated_statements_back_inserter++ =
                                        edge_statement_t{
                                            {{
                                                node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_from.current_node), u8"accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin()), c},
                                                node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"element", n},
                                            }},
                                            {{
                                                {u8"id", u8"tree_node_" + object_pointer_to_string(iterator_from.current_node) + u8"->accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin())},
                                                {u8"constraint", u8"false"},
                                                {u8"tailclip", u8"false"},
                                                {u8"color", iterator_from == iterator_root ? u8"#0000FF" : u8"#00B4B4"},
                                            }}};
                            }
                        }
                        return html_label_t{fonttable_t{table_t{
                            .BORDER = 0,
                            .CELLBORDER = 1,
                            .CELLSPACING = 0,
                            .PORT = u8"accumulated_storage",
                            .rows = {
                                row_t{[&]() -> decltype(row_t::cells)
                                    {
                                        decltype(row_t::cells) cells;
                                        for(element_t * const &p : parameters.datum)
                                        {
                                            decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_element_pointer(const_cast<element_t *>(p));
                                            text_t text_C1001{{textitem_t{std::make_pair(font_t{.COLOR = iterator_from == iterator_root ? u8"#0000FF" : u8"#00B4B4", .FACE = u8"Cambria Math"}, text_t{{textitem_t{iterator_from != iterator_to ? u8" " : u8"↓"}}})}}};
                                            cells.push_back(cell_t{
                                                .BGCOLOR = p == nullptr ? inactive_cell_color : active_cell_color,
                                                .PORT = u8"accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin()),
                                                .content = html_label_t{text_C1001},
                                            });
                                        }
                                        return cells;
                                    }()},
                            },
                        }}};
                    } break;
                    case accumulated_storage_node_type_e::read_range:
                    {
                        decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[parameters.container_index].node_end) p_node_end;
                        if constexpr(static_cast<augmented_containers::augmented_sequence_physical_representation_e>(typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::augmented_sequence_physical_representation_t{}) == augmented_containers::augmented_sequence_physical_representation_e::rb3p)
                            p_node_end = tagged_ptr_bit0_unsetted(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[parameters.container_index].node_end);
                        else if constexpr(static_cast<augmented_containers::augmented_sequence_physical_representation_e>(typename decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::augmented_sequence_physical_representation_t{}) == augmented_containers::augmented_sequence_physical_representation_e::rb2p)
                            p_node_end = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[parameters.container_index].node_end;
                        else std::unreachable();
                        for(element_t * const &p : parameters.datum)
                        {
                            if(p != nullptr)
                            {
                                decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_to = decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::from_element_pointer(const_cast<element_t *>(p));
                                parameters.converter_generated_statements_back_inserter++ =
                                    edge_statement_t{
                                        {{
                                            node_id_t{u8"read_range_" + object_pointer_to_string(p_node_end), u8"accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin()), c},
                                            node_id_t{u8"tree_node_" + object_pointer_to_string(iterator_to.current_node), u8"element", s},
                                        }},
                                        {{
                                            {u8"id", u8"read_range_" + object_pointer_to_string(p_node_end) + u8".accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin())},
                                            {u8"constraint", u8"false"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", u8"#0000FF"},
                                        }}};
                            }
                        }
                        return html_label_t{fonttable_t{table_t{
                            .BORDER = 0,
                            .CELLBORDER = 1,
                            .CELLSPACING = 0,
                            .PORT = u8"accumulated_storage",
                            .rows = {
                                row_t{[&]() -> decltype(row_t::cells)
                                    {
                                        decltype(row_t::cells) cells;
                                        for(element_t * const &p : parameters.datum)
                                        {
                                            cells.push_back(cell_t{
                                                .BGCOLOR = p == nullptr ? inactive_cell_color : active_cell_color,
                                                .PORT = u8"accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin()),
                                                .content = html_label_t{text_t{{{u8" "}}}},
                                            });
                                        }
                                        return cells;
                                    }()},
                            },
                        }}};
                    } break;
                    } },
                .iterators = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators),
                .iterators_container_index = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index),
                .read_range = true,
             }
         ))
    {
        result.push_back((std::ostringstream() << graph).str());
    }
    return result;
}
