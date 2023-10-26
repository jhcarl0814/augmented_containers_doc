
#ifndef AUGMENTED_DEQUE_EXAMPLE_PREFIX
    #define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) id
#endif

#include <augmented_containers/augmented_deque.hpp>
#include "augmented_deque_visualization.hpp"
#include <random>
#include <map>

std::random_device AUGMENTED_DEQUE_EXAMPLE_PREFIXING(rd); // Will be used to obtain a seed for the random number engine
std::mt19937 AUGMENTED_DEQUE_EXAMPLE_PREFIXING(gen)(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(rd)()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> AUGMENTED_DEQUE_EXAMPLE_PREFIXING(distrib)(0, 10);

struct alignas(std::max({alignof(void *), static_cast<std::size_t>(0b10)})) AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t)
{
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) *prev = nullptr, *next = nullptr;
};
struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_t)
{
    using projected_storage_t = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t);

    template<typename allocator_element_t, typename it_projected_storage_t, typename it_element_t> // when requested_stride==1
    void construct_projected_storage(allocator_element_t const &allocator_element, typename std::pointer_traits<typename std::allocator_traits<allocator_element_t>::pointer>::template rebind<projected_storage_t> pointer_projected_storage, [[maybe_unused]] it_projected_storage_t it_this_list_node, [[maybe_unused]] it_element_t it_also_this_list_node) const
    {
        using allocator_projected_storage_t = typename std::allocator_traits<allocator_element_t>::template rebind_alloc<projected_storage_t>;
        std::allocator_traits<allocator_projected_storage_t>::construct(augmented_containers::detail::utility::unmove(allocator_projected_storage_t(allocator_element)), std::to_address(pointer_projected_storage));
    }

    template<typename allocator_element_t>
    void destroy_projected_storage(allocator_element_t const &allocator_element, typename std::pointer_traits<typename std::allocator_traits<allocator_element_t>::pointer>::template rebind<projected_storage_t> pointer_projected_storage) const
    {
        using allocator_projected_storage_t = typename std::allocator_traits<allocator_element_t>::template rebind_alloc<projected_storage_t>;
        std::allocator_traits<allocator_projected_storage_t>::destroy(augmented_containers::detail::utility::unmove(allocator_projected_storage_t(allocator_element)), std::to_address(pointer_projected_storage));
    }

    template<typename it_projected_storage_t, typename it_element_t> // when requested_stride==1
    bool update_projected_storage(projected_storage_t &value, [[maybe_unused]] it_projected_storage_t it_this_list_node, [[maybe_unused]] it_element_t it_also_this_list_node) const
    {
        value = projected_storage_t();
        return true;
    }
};
struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t)
{
    struct alignas(std::max({alignof(void *), static_cast<std::size_t>(0b10)})) record_t
    {
        AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) *front = nullptr, *back = nullptr;
        friend bool operator==(record_t const &lhs, record_t const &rhs) = default;
    };
    std::map<std::size_t, record_t> records;
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t)
    () = default;
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t)
    (AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) const &other)
        : records(other.records)
    {
        using namespace augmented_containers::detail::language;
        for(std::pair<std::size_t const, record_t> &record : records)
        {
            assert(record.second.front != nullptr), tagged_ptr_bit0_unsetted(record.second.front)->prev = reinterpret_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) *>(tagged_ptr_bit0_setted(&record.second));
            assert(record.second.back != nullptr), tagged_ptr_bit0_unsetted(record.second.back)->next = reinterpret_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) *>(tagged_ptr_bit0_setted(&record.second));
        }
    }
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) &operator=(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) const &other) &
    {
        if(this == &other)
            return *this;
        records = other.records;
        using namespace augmented_containers::detail::language;
        for(std::pair<std::size_t const, record_t> &record : records)
        {
            assert(record.second.front != nullptr), tagged_ptr_bit0_unsetted(record.second.front)->prev = reinterpret_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) *>(tagged_ptr_bit0_setted(&record.second));
            assert(record.second.back != nullptr), tagged_ptr_bit0_unsetted(record.second.back)->next = reinterpret_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) *>(tagged_ptr_bit0_setted(&record.second));
        }
        return *this;
    }
    friend bool operator==(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) const &lhs, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) const &rhs) = default;
};
struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulating_group_by_binary_functor_t)
{
    using accumulated_storage_t = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t);

    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t)
    identity_element() const { return {}; }
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t)
    operator()(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) lhs, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) const &rhs) const;
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t)
    operator()(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) lhs, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) rhs) const;
};

struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_and_accumulator_group_by_t)
    : AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_t),
      augmented_containers::augmented_deque_helpers::accumulator_wrapping_accumulating_binary_functor_t<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulating_group_by_binary_functor_t)>
{};

augmented_containers::augmented_deque_t<
    int,
    std::allocator<int>,
    std::tuple< //
        std::pair<std::integral_constant<std::size_t, 1>, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_and_accumulator_group_by_t)> //
        > //
    >
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque);
std::vector AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element){
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element(),
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element(),
};

std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count)() { return decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count; }
std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count)() { return AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).size(); }

std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(calculate_group_by_s_key)(decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::element_t const &element) { return (element % 3 + 3) % 3; }
AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t)
AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulating_group_by_binary_functor_t)::operator()(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) lhs, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) const &rhs) const
{
    using namespace augmented_containers::detail::language;
    auto iterator_projected_storage_rhs = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) &>(rhs));
    auto iterator_element_rhs = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::to_iterator_element(iterator_projected_storage_rhs);
    std::size_t group_by_key = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(calculate_group_by_s_key)(*iterator_element_rhs);
    if(auto it = lhs.records.find(group_by_key); it == lhs.records.end())
    {
        it = lhs.records.insert({group_by_key, {tagged_ptr_bit0_setted(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) &>(rhs)), tagged_ptr_bit0_setted(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) &>(rhs))}}).first;
        tagged_ptr_bit0_unsetted(it->second.back)->next = tagged_ptr_bit0_unsetted(it->second.front)->prev = reinterpret_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) *>(tagged_ptr_bit0_setted(&it->second));
    }
    else
    {
        tagged_ptr_bit0_unsetted(it->second.back)->next = &const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) &>(rhs);
        const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) &>(rhs).prev = tagged_ptr_bit0_unsetted(it->second.back);
        it->second.back = tagged_ptr_bit0_setted(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) &>(rhs));
    }
    return lhs;
}
AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t)
AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulating_group_by_binary_functor_t)::operator()(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) lhs, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) rhs) const
{
    using namespace augmented_containers::detail::language;
    for(std::pair<std::size_t const, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t)::record_t> &record_rhs : rhs.records)
    {
        if(auto it = lhs.records.find(record_rhs.first); it == lhs.records.end())
        {
            it = lhs.records.insert(record_rhs).first;
            tagged_ptr_bit0_unsetted(it->second.back)->next = tagged_ptr_bit0_unsetted(it->second.front)->prev = reinterpret_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) *>(tagged_ptr_bit0_setted(&it->second));
        }
        else
        {
            tagged_ptr_bit0_unsetted(it->second.back)->next = tagged_ptr_bit0_unsetted(record_rhs.second.front);
            tagged_ptr_bit0_unsetted(record_rhs.second.front)->prev = tagged_ptr_bit0_unsetted(it->second.back);
            tagged_ptr_bit0_unsetted(record_rhs.second.back)->next = reinterpret_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) *>(tagged_ptr_bit0_setted(&it->second));
            it->second.back = record_rhs.second.back;
        }
    }
    return lhs;
}

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
            {if(iterator_element_is_front)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index] = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element();++index; });
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
            {if(iterator_element_is_back)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index] = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element();++index; });
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
    for(dot::graph_t &graph : to_graphs(
            AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque),
            to_graphs_parameters_t{
#ifndef __EMSCRIPTEN__
                .element_to_string_converter =
#endif
                    [](auto parameters) -> html_label_t
                { return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << parameters.datum).str().data()))}}}}; },
#ifndef __EMSCRIPTEN__
               .projected_and_accumulated_storage_to_string_converter_per_sequence =
#endif
                    std::make_tuple(std::make_pair(
                        [](auto parameters) -> html_label_t
                        {
                            using namespace augmented_containers::detail::language;
                            using namespace augmented_containers::detail::visualization;
                            auto iterator_projected_storage = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_group_by_node_t) &>(parameters.datum));
                            auto iterator_element = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::to_iterator_element(iterator_projected_storage);
                            std::u8string color_primary = std::map<std::size_t, std::u8string>{{0, u8"#FF0000"}, {1, u8"#00FF00"}, {2, u8"#0000FF"}}.at(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(calculate_group_by_s_key)(*iterator_element));
                            if(iterator_projected_storage->prev != nullptr)
                            {
                                if(tagged_ptr_bit0_is_setted(iterator_projected_storage->prev))
                                {
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node), u8"projected_storage.prev", c},
                                            node_id_t{u8"digit_node_end.accumulated_storage", u8"accumulated_storage_" + object_pointer_to_string(tagged_ptr_bit0_unsetted(iterator_projected_storage->prev)), n},
                                        }},
                                        {{
                                            {u8"id", u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node) + u8"->projected_storage.prev"},
                                            {u8"constraint", u8"true"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", color_primary},
                                            {u8"style", u8"dashed"},
                                        }}};
                                }
                                else
                                {
                                    auto iterator_projected_storage_prev = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(iterator_projected_storage->prev);
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node), u8"projected_storage.prev", c},
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_prev.current_list_node), u8"projected_storage"},
                                        }},
                                        {{
                                            {u8"id", u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node) + u8"->projected_storage.prev"},
                                            {u8"constraint", u8"false"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", color_primary},
                                        }}};
                                }
                            }
                            if(iterator_projected_storage->next != nullptr)
                            {
                                if(tagged_ptr_bit0_is_setted(iterator_projected_storage->next))
                                {
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node), u8"projected_storage.next", c},
                                            node_id_t{u8"digit_node_end.accumulated_storage", u8"accumulated_storage_" + object_pointer_to_string(tagged_ptr_bit0_unsetted(iterator_projected_storage->next)), n},
                                        }},
                                        {{
                                            {u8"id", u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node) + u8"->projected_storage.next"},
                                            {u8"constraint", u8"true"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", color_primary},
                                            {u8"style", u8"dashed"},
                                        }}};
                                }
                                else
                                {
                                    auto iterator_projected_storage_next = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(iterator_projected_storage->next);
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node), u8"projected_storage.next", c},
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_next.current_list_node), u8"projected_storage"},
                                        }},
                                        {{
                                            {u8"id", u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node) + u8"->projected_storage.next"},
                                            {u8"constraint", u8"false"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", color_primary},
                                        }}};
                                }
                            }
                            return html_label_t{fonttable_t{table_t{
                                .BORDER = 0,
                                .CELLBORDER = 1,
                                .CELLSPACING = 0,
                                .PORT = u8"projected_storage",
                                .rows = [&]()
                                {
                                    return decltype(table_t::rows){
                                        row_t{{
                                            cell_t{
                                                .BGCOLOR = iterator_projected_storage->prev == nullptr ? inactive_cell_color : active_cell_color,
                                                .PORT = u8"projected_storage.prev",
                                                .content = html_label_t{text_t{{{u8" "}}}},
                                            },
                                            cell_t{
                                                .BGCOLOR = iterator_projected_storage->next == nullptr ? inactive_cell_color : active_cell_color,
                                                .PORT = u8"projected_storage.next",
                                                .content = html_label_t{text_t{{{u8" "}}}},
                                            },
                                        }},
                                    };
                                }(),
                            }}};
                        },
                        [](auto parameters) -> html_label_t
                        {
                            using namespace augmented_containers::detail::language;
                            using namespace augmented_containers::detail::visualization;
                            for(std::pair<std::size_t const, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t)::record_t> const &record : parameters.datum.records)
                            {
                                std::u8string color_primary = std::map<std::size_t, std::u8string>{{0, u8"#FF0000"}, {1, u8"#00FF00"}, {2, u8"#0000FF"}}.at(record.first);
                                std::u8string color_secondary = std::map<std::size_t, std::u8string>{{0, u8"#AA0000"}, {1, u8"#00AA00"}, {2, u8"#0000AA"}}.at(record.first);
                                switch(parameters.accumulated_storage_node_type)
                                {
                                case accumulated_storage_node_type_e::uninitialized: std::unreachable(); break;
                                case accumulated_storage_node_type_e::read_range: std::unreachable(); break;
                                case accumulated_storage_node_type_e::digit_node_end_accumulated_storage:
                                {
                                    if(record.second.front != nullptr)
                                    {
                                        auto iterator_projected_storage_front = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(record.second.front));
                                        parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                            {{
                                                node_id_t{u8"digit_node_end.accumulated_storage", u8"accumulated_storage_" + object_pointer_to_string(&record.second) + u8".front", c},
                                                node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_front.current_list_node), u8"projected_storage"},
                                            }},
                                            {{
                                                {u8"id", u8"digit_node_end.accumulated_storage_" + object_pointer_to_string(&record.second) + u8".front"},
                                                {u8"constraint", u8"false"},
                                                {u8"tailclip", u8"false"},
                                                {u8"color", color_primary},
                                                {u8"style", u8"dashed"},
                                            }}};
                                    }
                                    if(record.second.back != nullptr)
                                    {
                                        auto iterator_projected_storage_back = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(record.second.back));
                                        parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                            {{
                                                node_id_t{u8"digit_node_end.accumulated_storage", u8"accumulated_storage_" + object_pointer_to_string(&record.second) + u8".back", c},
                                                node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_back.current_list_node), u8"projected_storage"},
                                            }},
                                            {{
                                                {u8"id", u8"digit_node_end.accumulated_storage_" + object_pointer_to_string(&record.second) + u8".back"},
                                                {u8"constraint", u8"false"},
                                                {u8"tailclip", u8"false"},
                                                {u8"color", color_primary},
                                                {u8"style", u8"dashed"},
                                            }}};
                                    }
                                } break;
                                case accumulated_storage_node_type_e::digit_node:
                                {
                                    auto digit_node = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::digit_node_t::from_accumulated_storage_pointer(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) &>(parameters.datum));
                                    if(record.second.front != nullptr)
                                    {
                                        auto iterator_projected_storage_front = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(record.second.front));
                                        parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                            {{
                                                node_id_t{u8"digit_node_" + object_pointer_to_string(digit_node), u8"accumulated_storage_" + object_pointer_to_string(&record.second) + u8".front", c},
                                                node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_front.current_list_node), u8"projected_storage"},
                                            }},
                                            {{
                                                {u8"id", u8"digit_node_" + object_pointer_to_string(digit_node) + u8"->accumulated_storage_" + object_pointer_to_string(&record.second) + u8".front"},
                                                {u8"constraint", u8"false"},
                                                {u8"tailclip", u8"false"},
                                                {u8"color", color_secondary},
                                                {u8"style", u8"dashed"},
                                            }}};
                                    }
                                    if(record.second.back != nullptr)
                                    {
                                        auto iterator_projected_storage_back = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(record.second.back));
                                        parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                            {{
                                                node_id_t{u8"digit_node_" + object_pointer_to_string(digit_node), u8"accumulated_storage_" + object_pointer_to_string(&record.second) + u8".back", c},
                                                node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_back.current_list_node), u8"projected_storage"},
                                            }},
                                            {{
                                                {u8"id", u8"digit_node_" + object_pointer_to_string(digit_node) + u8"->accumulated_storage_" + object_pointer_to_string(&record.second) + u8".back"},
                                                {u8"constraint", u8"false"},
                                                {u8"tailclip", u8"false"},
                                                {u8"color", color_secondary},
                                                {u8"style", u8"dashed"},
                                            }}};
                                    }
                                } break;
                                case accumulated_storage_node_type_e::tree_node:
                                {
                                    auto tree_node = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::tree_node_t::from_accumulated_storage_pointer(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t) &>(parameters.datum));
                                    if(record.second.front != nullptr)
                                    {
                                        auto iterator_projected_storage_front = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(record.second.front));
                                        parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                            {{
                                                node_id_t{u8"tree_node_" + object_pointer_to_string(tree_node), u8"accumulated_storage_" + object_pointer_to_string(&record.second) + u8".front", c},
                                                node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_front.current_list_node), u8"projected_storage"},
                                            }},
                                            {{
                                                {u8"id", u8"tree_node_" + object_pointer_to_string(tree_node) + u8"->accumulated_storage_" + object_pointer_to_string(&record.second) + u8".front"},
                                                {u8"constraint", u8"false"},
                                                {u8"tailclip", u8"false"},
                                                {u8"color", color_secondary},
                                                {u8"style", u8"dashed"},
                                            }}};
                                    }
                                    if(record.second.back != nullptr)
                                    {
                                        auto iterator_projected_storage_back = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(record.second.back));
                                        parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                            {{
                                                node_id_t{u8"tree_node_" + object_pointer_to_string(tree_node), u8"accumulated_storage_" + object_pointer_to_string(&record.second) + u8".back", c},
                                                node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_back.current_list_node), u8"projected_storage"},
                                            }},
                                            {{
                                                {u8"id", u8"tree_node_" + object_pointer_to_string(tree_node) + u8"->accumulated_storage_" + object_pointer_to_string(&record.second) + u8".back"},
                                                {u8"constraint", u8"false"},
                                                {u8"tailclip", u8"false"},
                                                {u8"color", color_secondary},
                                                {u8"style", u8"dashed"},
                                            }}};
                                    }
                                } break;
                                }
                            }
                            return html_label_t{fonttable_t{table_t{
                                .BORDER = 0,
                                .CELLBORDER = 1,
                                .CELLSPACING = 0,
                                .PORT = u8"accumulated_storage",
                                .rows = [&]()
                                {
                                    decltype(table_t::rows) rows;
                                    for(std::pair<std::size_t const, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_group_by_node_t)::record_t> const &record : parameters.datum.records)
                                    {
                                        decltype(table_t::rows) C1001_rows{
                                            row_t{{
                                                cell_t{
                                                    .PORT = u8"accumulated_storage_" + object_pointer_to_string(&record.second) + u8".front",
                                                    .content = html_label_t{text_t{{{u8" "}}}},
                                                },
                                                cell_t{
                                                    .PORT = u8"accumulated_storage_" + object_pointer_to_string(&record.second) + u8".back",
                                                    .content = html_label_t{text_t{{{u8" "}}}},
                                                },
                                            }},
                                        };
                                        rows.push_back(row_t{{
                                            cell_t{
                                                .content = html_label_t{text_t{{{index_to_string(record.first)}}}},
                                            },
                                            cell_t{
                                                .content = html_label_t{fonttable_t{table_t{
                                                    .BORDER = 0,
                                                    .CELLBORDER = 1,
                                                    .CELLSPACING = 0,
                                                    .PORT = u8"accumulated_storage_" + object_pointer_to_string(&record.second),
                                                    .rows = C1001_rows,
                                                }}},
                                            },
                                        }});
                                    }
                                    return rows;
                                }(),
                            }}};
                        })),
#ifndef __EMSCRIPTEN__
               .iterators_element =
#endif
                    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element),
#ifndef __EMSCRIPTEN__
               .read_range_per_sequence =
#endif
                    std::make_tuple(false),
            }))
        result.push_back((std::ostringstream() << graph).str());
    return result;
}
std::string AUGMENTED_DEQUE_EXAMPLE_PREFIXING(additional_info)()
{
    std::ostringstream oss;
    std::ranges::for_each(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element), [&, index = 0](auto iterator_element) mutable
        { oss << "it[" << index << "].index(): " << iterator_element.index()<< "; "<< "it[" << index << "].is_end(): " << std::boolalpha<< iterator_element.is_end() << ";" << /*R"(\l)"*/ "\n"; ++index; });
    if(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).size() >= 2)
    {
        oss << "it[0] <=> it[1]: " << [](std::weak_ordering cmp)
        { return cmp < 0 ? -1 : (cmp > 0 ? 1 : 0); }(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0] <=> AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[1])
            << "; "
            << "it[1] - it[0]: " << (AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[1] - AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0]) << ";" << /*R"(\l)"*/ "\n";
    }
    return oss.str();
}
