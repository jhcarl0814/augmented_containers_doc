
#ifndef AUGMENTED_DEQUE_EXAMPLE_PREFIX
    #define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) id
#endif

#include "augmented_deque.hpp"
#include "augmented_deque_visualization.hpp"
#include <random>
#include <array>

std::random_device AUGMENTED_DEQUE_EXAMPLE_PREFIXING(rd); // Will be used to obtain a seed for the random number engine
std::mt19937 AUGMENTED_DEQUE_EXAMPLE_PREFIXING(gen)(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(rd)()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> AUGMENTED_DEQUE_EXAMPLE_PREFIXING(distrib)(0, 10);

template<typename element_t, std::size_t N, bool reverse = false>
struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_min_n_element_t)
{
    using projected_storage_t = std::array<element_t *, N>;

    template<typename it_element_t>
    projected_storage_t project_n_ary_functor(it_element_t it_chunk_begin, it_element_t it_chunk_end, std::size_t chunk_size) const
    {
        assert(chunk_size <= N);
        projected_storage_t result{};
        std::ranges::transform(std::ranges::subrange(it_chunk_begin, it_chunk_end), result.begin(), [](element_t const &element)
            { return &const_cast<element_t &>(element); });
        std::ranges::stable_sort(result | std::views::take(chunk_size), [](element_t * const &lhs, element_t * const &rhs)
            {
                if constexpr(!reverse)
                    return (*lhs <=> *rhs) != std::strong_ordering::greater;
                else
                    return !((*lhs <=> *rhs) != std::strong_ordering::greater); });
        return result;
    }

    template<typename allocator_element_t, typename it_element_t> // when requested_stride>1
    projected_storage_t construct_projected_storage([[maybe_unused]] allocator_element_t const &allocator_element, it_element_t it_chunk_begin, it_element_t it_chunk_end, std::size_t chunk_size) const
    {
        assert(chunk_size != 0);
        return projected_storage_t(project_n_ary_functor(it_chunk_begin, it_chunk_end, chunk_size));
    }
    template<typename allocator_element_t, typename it_projected_storage_t, typename it_element_t> // when requested_stride>1
    void construct_projected_storage(allocator_element_t const &allocator_element, typename std::pointer_traits<typename std::allocator_traits<allocator_element_t>::pointer>::template rebind<projected_storage_t> pointer_projected_storage, [[maybe_unused]] it_projected_storage_t it_this_list_node, it_element_t it_chunk_begin, it_element_t it_chunk_end, std::size_t chunk_size) const
    {
        assert(chunk_size != 0);
        using allocator_projected_storage_t = typename std::allocator_traits<allocator_element_t>::template rebind_alloc<projected_storage_t>;
        std::allocator_traits<allocator_projected_storage_t>::construct(augmented_containers::detail::utility::unmove(allocator_projected_storage_t(allocator_element)), std::to_address(pointer_projected_storage), project_n_ary_functor(it_chunk_begin, it_chunk_end, chunk_size));
    }

    template<typename allocator_element_t>
    void destroy_projected_storage(allocator_element_t const &allocator_element, typename std::pointer_traits<typename std::allocator_traits<allocator_element_t>::pointer>::template rebind<projected_storage_t> pointer_projected_storage) const
    {
        using allocator_projected_storage_t = typename std::allocator_traits<allocator_element_t>::template rebind_alloc<projected_storage_t>;
        std::allocator_traits<allocator_projected_storage_t>::destroy(augmented_containers::detail::utility::unmove(allocator_projected_storage_t(allocator_element)), std::to_address(pointer_projected_storage));
    }

    template<typename it_projected_storage_t, typename it_element_t> // when requested_stride>1
    bool update_projected_storage(projected_storage_t &value, [[maybe_unused]] it_projected_storage_t it_this_list_node, it_element_t it_chunk_begin, it_element_t it_chunk_end, std::size_t chunk_size) const
    {
        assert(chunk_size != 0);
        projected_storage_t value_new(project_n_ary_functor(it_chunk_begin, it_chunk_end, chunk_size));
        if(value == value_new)
            return false;
        else
        {
            value = value_new;
            return true;
        }
    }
};
template<typename element_t, std::size_t N, bool reverse = false>
struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulating_min_n_element_binary_functor_t)
{
    using accumulated_storage_t = std::array<element_t *, N>;

    accumulated_storage_t identity_element() const { return {}; }
    accumulated_storage_t operator()(accumulated_storage_t const &lhs, accumulated_storage_t const &rhs) const
    {
        accumulated_storage_t result{};
        auto in1 = lhs.begin(), in1_end = lhs.end(), in2 = rhs.begin(), in2_end = rhs.end();
        auto out = result.begin(), out_end = result.end();
        while(in1 != in1_end && *in1 != nullptr && in2 != in2_end && *in2 != nullptr && out != out_end)
        {
            if([&]()
                {
                if constexpr (!reverse)
                  return (**in1 <=> **in2) != std::strong_ordering::greater;
                else
                  return !((**in1 <=> **in2) != std::strong_ordering::greater); }())
                *out++ = *in1++;
            else
                *out++ = *in2++;
        }
        while(in1 != in1_end && *in1 != nullptr && out != out_end)
            *out++ = *in1++;
        while(in2 != in2_end && *in2 != nullptr && out != out_end)
            *out++ = *in2++;
        return result;
    }
};

template<typename element_t, std::size_t N, bool reverse = false>
struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_and_accumulator_min_n_element_t)
    : AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_min_n_element_t)<element_t, N, reverse>,
      augmented_containers::augmented_deque_helpers::accumulator_wrapping_accumulating_binary_functor_t < AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulating_min_n_element_binary_functor_t) < element_t,
      N,
      reverse >>
{};

augmented_containers::augmented_deque_t<
    int,
    std::allocator<int>,
    std::tuple< //
        //std::pair<std::integral_constant<std::size_t, 3>, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_and_accumulator_min_n_element_t) < int, 3>>, //
        std::pair<std::integral_constant<std::size_t, 3>, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_and_accumulator_min_n_element_t) < int, 3, true>> //
    > //
    > AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque);
std::vector AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element){
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element(),
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element(),
};

std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count)() { return decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count; }
std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count)() { return AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).size(); }

// iterators
std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index)(std::size_t iterator_element_index) { return AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[iterator_element_index].index(); }
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index)(std::size_t iterator_element_index, std::ptrdiff_t index)
{
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)
    [iterator_element_index] = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element() + index;
}
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment)(std::size_t iterator_index) { ++AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[iterator_index]; }
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement)(std::size_t iterator_index) { --AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[iterator_index]; }
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance)(std::size_t iterator_index, std::ptrdiff_t offset)
{
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)
    [iterator_index] += offset;
}

// element access
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output)(std::size_t iterator_index, std::string value)
{
    if(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[iterator_index] != AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element())
        *AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[iterator_index] = [&value]()
        {
            int value_int;
            std::istringstream(value) >> value_int;
            return value_int;
        }();
}

// modifiers
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front)() { AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).push_front(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(distrib)(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(gen))); }
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back)() { AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).push_back(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(distrib)(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(gen))); }
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front)()
{
    if(!AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).empty())
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterator_element_is_front_list;
        std::transform(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).begin(), AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).end(), std::back_inserter(iterator_element_is_front_list), [](auto iterator_element)
            { return iterator_element == AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element(); });
#else
        std::vector<bool> iterator_element_is_front_list = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element) | std::views::transform([](auto iterator_element)
                                                                                                                                      { return iterator_element == AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element(); }) |
            std::ranges::to<std::vector>();
#endif
        AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).pop_front();
        std::ranges::for_each(iterator_element_is_front_list, [index = 0](bool iterator_element_is_front) mutable
            {if(iterator_element_is_front)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index] = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque) .sequence<0>() .begin_element();++index; });
    }
}
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back)()
{
    if(!AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).empty())
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterator_element_is_back_list;
        std::transform(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).begin(), AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).end(), std::back_inserter(iterator_element_is_back_list), [](auto iterator_element)
            { return iterator_element == --augmented_containers::detail::utility::unmove(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element()); });
#else
        std::vector<bool> iterator_element_is_back_list = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element) | std::views::transform([](auto iterator_element)
                                                                                                                                     { return iterator_element == --augmented_containers::detail::utility::unmove(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element()); }) |
            std::ranges::to<std::vector>();
#endif
        AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).pop_back();
        std::ranges::for_each(iterator_element_is_back_list, [index = 0](bool iterator_element_is_back) mutable
            {if(iterator_element_is_back)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index] = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque) .sequence<0>() .end_element();++index; });
    }
}
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range)()
{
    if(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0] <= AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[1])
        AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).update_range(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0], AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[1]);
}

std::vector<std::string> AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string)()
{
    std::vector<std::string> result;
    using namespace dot;
    using namespace augmented_containers::detail::visualization::augmented_deque;
    for(dot::graph_t &graph : to_graphs(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque),
            to_graphs_parameters_t{
#ifndef __EMSCRIPTEN__
                .element_to_string_converter =
#endif
                    [](auto parameters) -> html_label_t
                {
                    return html_label_t{fonttable_t{table_t{
                        .BORDER = 0,
                        .CELLBORDER = 1,
                        .CELLSPACING = 0,
                        .PORT = u8"element",
                        .rows = [&]()
                        {
                            return decltype(table_t::rows){
                                row_t{{cell_t{
                                    .content = html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << parameters.datum).str().data()))}}}},
                                }}},
                            };
                        }(),
                    }}};
                },
#ifndef __EMSCRIPTEN__
               .projected_and_accumulated_storage_to_string_converter_per_sequence =
#endif
                    std::make_tuple(
                        std::make_pair(std::nullopt, std::nullopt),
                        std::make_pair([](auto parameters) -> html_label_t
                            {
                                using namespace augmented_containers::detail::language;
                                using namespace augmented_containers::detail::visualization;
                                using element_t = typename decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::element_t;
                                using projected_storage_t =typename decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<1>::projected_storage_t;
                                auto iterator_projected_storage =decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<1>:: iterator_projected_storage_t::from_projected_storage_pointer(&const_cast<projected_storage_t &>(parameters.datum));
                                for(element_t * const &p : parameters.datum)
                                {
                                    if(p != nullptr)
                                    {
                                        auto iterator_element =decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t::from_element_pointer(p);
                                        parameters.converter_generated_statements_back_inserter++ =edge_statement_t{{{
                                                                                                                         node_id_t{u8"list_node_" +object_pointer_to_string(iterator_projected_storage .current_list_node), u8"projected_storage.element" +index_to_string(&p - &*parameters.datum.begin()),c},
                                                                                                                         node_id_t{u8"list_node_" +object_pointer_to_string(iterator_element.current_list_node),u8"element", n},
                                                                                                                         }},
                                            {{
                                                {u8"id",u8"list_node_" +object_pointer_to_string(iterator_projected_storage.current_list_node) +u8"->projected_storage.element" +index_to_string(&p - &*parameters.datum.begin())},
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
                                    .PORT = u8"projected_storage",
                                    .rows ={
                                        row_t{[&](){
                                            decltype(row_t::cells) cells;
                                                for(element_t * const &p :parameters.datum)
                                                {
                                                    cells.push_back(cell_t{
                                                        .BGCOLOR =p == nullptr? inactive_cell_color: active_cell_color,
                                                        .PORT =u8"projected_storage.element" +index_to_string(&p - &*parameters.datum.begin()),
                                                        .content = html_label_t{text_t{{{u8" "}}}},
                                                        });
                                                }
                                                return cells;
                                            }()},
                                        },
                                    }}}; },
                            [](auto parameters) -> html_label_t
                            {
                                using namespace augmented_containers::detail::language;
                                using namespace augmented_containers::detail::visualization;
                                using element_t = typename decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::element_t;
                                using accumulated_storage_t = typename decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<1>::accumulated_storage_t;
                                switch(parameters.accumulated_storage_node_type)
                                {
                                case accumulated_storage_node_type_e::uninitialized: std::unreachable(); break;
                                case accumulated_storage_node_type_e::digit_node_end_accumulated_storage:
                                {
                                    for(element_t * const &p : parameters.datum)
                                    {
                                        if(p != nullptr)
                                        {
                                            auto iterator_element = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t::from_element_pointer(p);
                                            parameters.converter_generated_statements_back_inserter++ = edge_statement_t{{{
                                                                                                                             node_id_t{u8"digit_node_end.accumulated_storage", u8"accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin()), c},
                                                                                                                             node_id_t{u8"list_node_" + object_pointer_to_string(iterator_element.current_list_node), u8"element"},
                                                                                                                         }},
                                                {{
                                                    {u8"id", u8"digit_node_end.accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin())},
                                                    {u8"constraint", u8"false"},
                                                    {u8"tailclip", u8"false"},
                                                    {u8"color", u8"#0000FF"},
                                                }}};
                                        }
                                    }
                                } break;
                                case accumulated_storage_node_type_e::digit_node:
                                {
                                    auto digit_node = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<1>::digit_node_t::from_accumulated_storage_pointer(&const_cast<accumulated_storage_t &>(parameters.datum));
                                    for(element_t * const &p : parameters.datum)
                                    {
                                        if(p != nullptr)
                                        {
                                            auto iterator_element = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t::from_element_pointer(p);
                                            parameters.converter_generated_statements_back_inserter++ = edge_statement_t{{{
                                                                                                                             node_id_t{u8"digit_node_" + object_pointer_to_string(digit_node), u8"accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin()),
                                                                                                                                 c},
                                                                                                                             node_id_t{u8"list_node_" + object_pointer_to_string(iterator_element.current_list_node), u8"element", n},
                                                                                                                         }},
                                                {{
                                                    {u8"id", u8"digit_node_" + object_pointer_to_string(digit_node) + u8"->accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin())},
                                                    {u8"constraint", u8"false"},
                                                    {u8"tailclip", u8"false"},
                                                    {u8"color", u8"#0000FF"},
                                                }}};
                                        }
                                    }
                                } break;
                                case accumulated_storage_node_type_e::tree_node:
                                {
                                    auto tree_node = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<1>::tree_node_t::from_accumulated_storage_pointer(&const_cast<accumulated_storage_t &>(parameters.datum));
                                    for(element_t * const &p : parameters.datum)
                                    {
                                        if(p != nullptr)
                                        {
                                            auto iterator_element = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t::from_element_pointer(p);
                                            parameters
                                                .converter_generated_statements_back_inserter++ =
                                                edge_statement_t{
                                                    {{
                                                        node_id_t{u8"tree_node_" + object_pointer_to_string(tree_node), u8"accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin()),
                                                            c},
                                                        node_id_t{u8"list_node_" + object_pointer_to_string(iterator_element.current_list_node), u8"element", n},
                                                    }},
                                                    {{
                                                        {u8"id", u8"tree_node_" + object_pointer_to_string(tree_node) + u8"->accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin())},
                                                        {u8"constraint", u8"false"},
                                                        {u8"tailclip", u8"false"},
                                                        {u8"color", u8"#0000FF"},
                                                    }}};
                                        }
                                    }
                                } break;
                                case accumulated_storage_node_type_e::read_range:
                                {
                                    auto tree_node = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<1>::tree_node_t::from_accumulated_storage_pointer(&const_cast<accumulated_storage_t &>(parameters.datum));
                                    for(element_t * const &p : parameters.datum)
                                    {
                                        if(p != nullptr)
                                        {
                                            auto iterator_element = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t::from_element_pointer(p);
                                            parameters
                                                .converter_generated_statements_back_inserter++ =
                                                edge_statement_t{
                                                    {{
                                                        node_id_t{u8"read_range", u8"accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin()), c},
                                                        node_id_t{u8"list_node_" + object_pointer_to_string(iterator_element.current_list_node), u8"element"},
                                                    }},
                                                    {{
                                                        {u8"id", u8"read_range.accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin())},
                                                        {u8"constraint", u8"false"},
                                                        {u8"tailclip", u8"false"},
                                                        {u8"color", u8"#0000FF"},
                                                    }}};
                                        }
                                    }
                                } break;
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
                            }) /*,
                        std::make_pair([](auto parameters) -> html_label_t
                            {
                                using namespace augmented_containers::detail::language;
                                using namespace augmented_containers::detail::visualization;
                                using element_t = typename decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::element_t;
                                using projected_storage_t =typename decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<2>::projected_storage_t;
                                auto iterator_projected_storage =decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<2>::iterator_projected_storage_t::from_projected_storage_pointer(&const_cast<projected_storage_t &>(parameters.datum));
                                for(element_t * const &p : parameters.datum)
                                {
                                    if(p != nullptr)
                                    {
                                        auto iterator_element =decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t::from_element_pointer(p);
                                        parameters.converter_generated_statements_back_inserter++ =edge_statement_t{
                                                {{
                                                    node_id_t{u8"list_node_" +object_pointer_to_string(iterator_projected_storage.current_list_node),u8"projected_storage.element" +index_to_string(&p - &*parameters.datum.begin()),c},
                                                    node_id_t{u8"list_node_" +object_pointer_to_string(iterator_element.current_list_node),u8"element", n},
                                                }},
                                                {{
                                                    {u8"id",u8"list_node_" +object_pointer_to_string(iterator_projected_storage.current_list_node) +u8"->projected_storage.element" +index_to_string(&p - &*parameters.datum.begin())},
                                                    {u8"constraint", u8"false"},
                                                    {u8"tailclip", u8"false"},
                                                    {u8"color", u8"#00B4B4"},
                                                }}};
                                    }
                                }
                                return html_label_t{fonttable_t{table_t{
                                    .BORDER = 0,
                                    .CELLBORDER = 1,
                                    .CELLSPACING = 0,
                                    .PORT = u8"projected_storage",
                                    .rows =
                                        {
                                            row_t{[&]()
                                                {
                                                    decltype(row_t::cells) cells;
                                                    for(element_t * const &p :parameters.datum)
                                                    {
                                                        cells.push_back(cell_t{
                                                            .BGCOLOR =p == nullptr? inactive_cell_color: active_cell_color,
                                                            .PORT =u8"projected_storage.element" +index_to_string(&p - &*parameters.datum.begin()),
                                                            .content = html_label_t{text_t{{{u8" "}}}},
                                                        });
                                                    }
                                                    return cells;
                                                }()},
                                        },
                                }}}; },
                            [](auto parameters) -> html_label_t
                            {
                                using namespace augmented_containers::detail::language;
                                using namespace augmented_containers::detail::visualization;
                                using element_t = typename decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::element_t;
                                using accumulated_storage_t = typename decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<2>::accumulated_storage_t;
                                switch(parameters.accumulated_storage_node_type)
                                {
                                case accumulated_storage_node_type_e::uninitialized: std::unreachable(); break;
                                case accumulated_storage_node_type_e::digit_node_end_accumulated_storage:
                                {
                                    for(element_t * const &p : parameters.datum)
                                    {
                                        if(p != nullptr)
                                        {
                                            auto iterator_element = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t::from_element_pointer(p);
                                            parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                                {{
                                                    node_id_t{u8"digit_node_end.accumulated_storage",u8"accumulated_storage.element" +index_to_string(&p - &*parameters.datum.begin()),c},
                                                    node_id_t{u8"list_node_" + object_pointer_to_string(iterator_element.current_list_node), u8"element"},
                                                }},
                                                {{
                                                    {u8"id", u8"digit_node_end.accumulated_storage.element" +index_to_string(&p - &*parameters.datum.begin())},
                                                    {u8"constraint", u8"false"},
                                                    {u8"tailclip", u8"false"},
                                                    {u8"color", u8"#00B4B4"},
                                                }}};
                                        }
                                    }
                                } break;
                                case accumulated_storage_node_type_e::digit_node:
                                {
                                    auto digit_node = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<2>::digit_node_t::from_accumulated_storage_pointer(&const_cast<accumulated_storage_t &>(parameters.datum));
                                    for(element_t * const &p : parameters.datum)
                                    {
                                        if(p != nullptr)
                                        {
                                            auto iterator_element = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t::from_element_pointer(p);
                                            parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                                {{
                                                    node_id_t{u8"digit_node_" + object_pointer_to_string(digit_node), u8"accumulated_storage.element" +index_to_string(&p - &*parameters.datum.begin()),c},
                                                    node_id_t{u8"list_node_" + object_pointer_to_string(iterator_element.current_list_node), u8"element", n},
                                                }},
                                                {{
                                                    {u8"id", u8"digit_node_" + object_pointer_to_string(digit_node) + u8"->accumulated_storage.element" +index_to_string(&p - &*parameters.datum.begin())},
                                                    {u8"constraint", u8"false"},
                                                    {u8"tailclip", u8"false"},
                                                    {u8"color", u8"#00B4B4"},
                                                }}};
                                        }
                                    }
                                } break;
                                case accumulated_storage_node_type_e::tree_node:
                                {
                                    auto tree_node = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<2>::tree_node_t::from_accumulated_storage_pointer(&const_cast<accumulated_storage_t &>(parameters.datum));
                                    for(element_t * const &p : parameters.datum)
                                    {
                                        if(p != nullptr)
                                        {
                                            auto iterator_element = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t::from_element_pointer(p);
                                            parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                                {{
                                                    node_id_t{u8"tree_node_" + object_pointer_to_string(tree_node), u8"accumulated_storage.element" +index_to_string(&p - &*parameters.datum.begin()),c},
                                                    node_id_t{u8"list_node_" + object_pointer_to_string(iterator_element.current_list_node), u8"element", n},
                                                }},
                                                {{
                                                    {u8"id", u8"tree_node_" + object_pointer_to_string(tree_node) + u8"->accumulated_storage.element" + index_to_string(&p - &*parameters.datum.begin())},
                                                    {u8"constraint", u8"false"},
                                                    {u8"tailclip", u8"false"},
                                                    {u8"color", u8"#00B4B4"},
                                                }}};
                                        }
                                    }
                                } break;
                                case accumulated_storage_node_type_e::read_range:
                                {
                                    auto tree_node = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<2>::tree_node_t::from_accumulated_storage_pointer(&const_cast<accumulated_storage_t &>(parameters.datum));
                                    for(element_t * const &p : parameters.datum)
                                    {
                                        if(p != nullptr)
                                        {
                                            auto iterator_element = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t::from_element_pointer(p);
                                            parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                                {{
                                                    node_id_t{u8"read_range", u8"accumulated_storage.element" +index_to_string(&p - &*parameters.datum.begin()),c},
                                                    node_id_t{u8"list_node_" + object_pointer_to_string(iterator_element.current_list_node), u8"element"},
                                                }},
                                                {{
                                                    {u8"id", u8"read_range.accumulated_storage.element" +index_to_string(&p - &*parameters.datum.begin())},
                                                    {u8"constraint", u8"false"},
                                                    {u8"tailclip", u8"false"},
                                                    {u8"color", u8"#00B4B4"},
                                                }}};
                                        }
                                    }
                                } break;
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
                            })*/
                        ),
#ifndef __EMSCRIPTEN__
               .iterators_element =
#endif
                    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element),
#ifndef __EMSCRIPTEN__
               .read_range_per_sequence =
#endif
                    std::make_tuple(false, true, true),
            }))
        result.push_back((std::ostringstream() << graph).str());
    return result;
}
std::string AUGMENTED_DEQUE_EXAMPLE_PREFIXING(additional_info)()
{
    std::ostringstream oss;
    std::ranges::for_each(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element), [&, index = 0](auto iterator_element) mutable
        {  oss << "it[" << index << "].index(): " << iterator_element.index() << "; " << "it[" << index << "].is_end(): " << std::boolalpha << iterator_element.is_end() << ";" << /*R"(\l)"*/ "\n"; ++index; });
    if(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).size() >= 2)
    {
        oss << "it[0] <=> it[1]: " << [](std::weak_ordering cmp)
        { return cmp < 0 ? -1 : (cmp > 0 ? 1 : 0); }(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0] <=> AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[1])
            << "; "
            << "it[1] - it[0]: " << (AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[1] - AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0]) << ";" << /*R"(\l)"*/ "\n";
    }
    return oss.str();
}
