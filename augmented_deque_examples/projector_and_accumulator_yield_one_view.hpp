
#ifndef AUGMENTED_DEQUE_EXAMPLE_PREFIX
    #define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) id
#endif

#include "augmented_deque.hpp"
#include "augmented_deque_visualization.hpp"
#include <random>

std::random_device AUGMENTED_DEQUE_EXAMPLE_PREFIXING(rd); // Will be used to obtain a seed for the random number engine
std::mt19937 AUGMENTED_DEQUE_EXAMPLE_PREFIXING(gen)(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(rd)()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> AUGMENTED_DEQUE_EXAMPLE_PREFIXING(distrib)(0, 100);

struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t)
{
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) *prev = nullptr, *next = nullptr;
};
struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_t)
{
    using projected_storage_t = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t);

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
struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t)
{
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) *front = nullptr, *back = nullptr;
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t)
    () = default;
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t)
    (AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) * front, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) * back)
        : front(front),
          back(back)
    {
        using namespace augmented_containers::detail::language;
        if(front != nullptr)
            tagged_ptr_bit0_unsetted(front)->prev = reinterpret_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) *>(tagged_ptr_bit0_setted(this));
        if(back != nullptr)
            tagged_ptr_bit0_unsetted(back)->next = reinterpret_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) *>(tagged_ptr_bit0_setted(this));
    }
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t)
    (AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) const &other)
        : AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t)(other.front, other.back)
    {}
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) &operator=(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) const &other) &
    {
        using namespace augmented_containers::detail::language;
        if((front = other.front) != nullptr)
            tagged_ptr_bit0_unsetted(front)->prev = reinterpret_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) *>(tagged_ptr_bit0_setted(this));
        if((back = other.back) != nullptr)
            tagged_ptr_bit0_unsetted(back)->next = reinterpret_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) *>(tagged_ptr_bit0_setted(this));
        return *this;
    }
    friend bool operator==(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) const &lhs, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) const &rhs) = default;
};
struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(
    accumulating_diffing_adjacent_element_binary_functor_t)
{
    using accumulated_storage_t = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t);

    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t)
    identity_element() const { return {nullptr, nullptr}; }
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t)
    operator()(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) lhs, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) const &rhs) const;
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t)
    operator()(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) lhs, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) rhs) const;
};

struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_and_accumulator_diffing_adjacent_element_t)
    : AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_t),
      augmented_containers::augmented_deque_helpers::accumulator_wrapping_accumulating_binary_functor_t<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)>
{};

augmented_containers::augmented_deque_t<
    int,
    std::allocator<int>,
    std::tuple< //
        std::pair<std::integral_constant<std::size_t, 1>, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_and_accumulator_diffing_adjacent_element_t)> //
        > //
    >
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque);
std::vector AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element){
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element(),
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element(),
};

std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count)() { return decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count; }
std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count)() { return AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).size(); }

bool AUGMENTED_DEQUE_EXAMPLE_PREFIXING(is_front_of_chunk)(decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t iterator_element)
{
    if(auto iterator_element_prev =
#ifdef __EMSCRIPTEN__
            std::prev
#else
            std::ranges::prev
#endif
        (iterator_element);
        iterator_element_prev.is_end())
        return true;
    else
        return (*iterator_element_prev < 50) != (*iterator_element < 50);
}
AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t)
AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::operator()(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) lhs, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) const &rhs) const
{
    using namespace augmented_containers::detail::language;
    auto iterator_projected_storage_rhs = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) &>(rhs));
    auto iterator_element_rhs = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::to_iterator_element(iterator_projected_storage_rhs);
    if(lhs.front == nullptr && lhs.back == nullptr)
    {
        if(!AUGMENTED_DEQUE_EXAMPLE_PREFIXING(is_front_of_chunk)(iterator_element_rhs))
            return {};
        else
            return {tagged_ptr_bit0_setted(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) &>(rhs)), tagged_ptr_bit0_setted(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) &>(rhs))};
    }
    else if(lhs.front != nullptr && lhs.back != nullptr)
    {
        if(!AUGMENTED_DEQUE_EXAMPLE_PREFIXING(is_front_of_chunk)(iterator_element_rhs))
            return lhs;
        else
        {
            tagged_ptr_bit0_unsetted(lhs.back)->next = &const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) &>(rhs);
            const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) &>(rhs).prev = tagged_ptr_bit0_unsetted(lhs.back);
            return {lhs.front, tagged_ptr_bit0_setted(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) &>(rhs))};
        }
    }
    else std::unreachable();
}
AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t)
AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulating_diffing_adjacent_element_binary_functor_t)::operator()(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) lhs, AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) rhs) const
{
    using namespace augmented_containers::detail::language;
    if(lhs.front == nullptr && lhs.back == nullptr)
    {
        if(rhs.front == nullptr && rhs.back == nullptr)
            return {};
        else if(rhs.front != nullptr && rhs.back != nullptr)
            return rhs;
        else std::unreachable();
    }
    else if(lhs.front != nullptr && lhs.back != nullptr)
    {
        if(rhs.front == nullptr && rhs.back == nullptr)
            return lhs;
        else if(rhs.front != nullptr && rhs.back != nullptr)
        {
            tagged_ptr_bit0_unsetted(lhs.back)->next = tagged_ptr_bit0_unsetted(rhs.front);
            tagged_ptr_bit0_unsetted(rhs.front)->prev = tagged_ptr_bit0_unsetted(lhs.back);
            return {lhs.front, rhs.back};
        }
        else std::unreachable();
    }
    else std::unreachable();
}

// iterators
std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index)(std::size_t iterator_element_index) { return AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[iterator_element_index].index(); }
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index)(std::size_t iterator_element_index, std::size_t index)
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
        *AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[iterator_index] = [value]()
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
#ifdef __EMSCRIPTEN__
        std::for_each(iterator_element_is_front_list.begin(), iterator_element_is_front_list.end(), [index = 0](bool iterator_element_is_front) mutable
            {
                if(iterator_element_is_front)
                    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index] = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element();
                ++index; });
#else
        std::ranges::for_each(iterator_element_is_front_list, [index = 0](bool iterator_element_is_front) mutable
            {
                if(iterator_element_is_front)
                    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index] = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element();
                ++index; });
#endif
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
#ifdef __EMSCRIPTEN__
        std::for_each(iterator_element_is_back_list.begin(), iterator_element_is_back_list.end(), [index = 0](bool iterator_element_is_back) mutable
            {
                if(iterator_element_is_back)
                    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index] = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element();
                ++index; });
#else
        std::ranges::for_each(iterator_element_is_back_list, [index = 0](bool iterator_element_is_back) mutable
            {
                if(iterator_element_is_back)
                    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index] = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element();
                ++index; });
#endif
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
    for(dot::graph_t &graph : to_graphs(
            AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque),
            augmented_containers::to_graphs_parameters_t{
#ifndef __EMSCRIPTEN__
                .element_to_string_converter =
#endif
                    [](auto parameters) -> html_label_t
                {
                    if(true)
                        return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << parameters.datum).str().data()))}}}};
                    else if(true)
                        return html_label_t{text_t{{
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data()) << ':' << parameters.datum).str().data()))},
                        }}};
                    else
                        return html_label_t{text_t{{
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data())).str().data()))},
                            {br_t{.ALIGN = LEFT}},
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << parameters.datum).str().data()))},
                            {br_t{.ALIGN = LEFT}},
                        }}};
                },
#ifndef __EMSCRIPTEN__
               .projected_and_accumulated_storage_to_string_converter_per_sequence =
#endif
                    std::make_tuple(std::make_pair(
                        [](auto parameters) -> html_label_t
                        {
                            using namespace augmented_containers::detail::language;
                            using namespace augmented_containers::detail::visualization;
                            auto iterator_projected_storage = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projector_diffing_adjacent_element_node_t) &>(parameters.datum));
                            if(iterator_projected_storage->prev != nullptr)
                            {
                                if(tagged_ptr_bit0_is_set(iterator_projected_storage->prev))
                                {
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node), u8"projected_storage.prev", c},
                                            node_id_t{u8"digit_node_end."
                                                      u8"accumulated_storage",
                                                u8"accumulated_storage"},
                                        }},
                                        {{
                                            {u8"id", u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node) + u8"->projected_storage.prev"},
                                            {u8"constraint", u8"true"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", u8"#0000FF"},
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
                                            {u8"color", u8"#0000FF"},
                                        }}};
                                }
                            }
                            if(iterator_projected_storage->next != nullptr)
                            {
                                if(tagged_ptr_bit0_is_set(iterator_projected_storage->next))
                                {
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node), u8"projected_storage.next", c},
                                            node_id_t{u8"digit_node_end."
                                                      u8"accumulated_storage",
                                                u8"accumulated_storage"},
                                        }},
                                        {{
                                            {u8"id", u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node) + u8"->projected_storage.next"},
                                            {u8"constraint", u8"true"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", u8"#0000FF"},
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
                                            {u8"color", u8"#0000FF"},
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
                            switch(parameters.accumulated_storage_node_type)
                            {
                            case accumulated_storage_node_type_t::digit_node_end_accumulated_storage:
                            {
                                if(parameters.datum.front != nullptr)
                                {
                                    auto iterator_projected_storage_front = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(parameters.datum.front));
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"digit_node_end."
                                                      u8"accumulated_storage",
                                                u8"accumulated_storage.front", c},
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_front.current_list_node), u8"projected_storage"},
                                        }},
                                        {{
                                            {u8"id", u8"digit_node_end.accumulated_"
                                                     u8"storage.front"},
                                            {u8"constraint", u8"false"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", u8"#0000FF"},
                                            {u8"style", u8"dashed"},
                                        }}};
                                }
                                if(parameters.datum.back != nullptr)
                                {
                                    auto iterator_projected_storage_back = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(parameters.datum.back));
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"digit_node_end."
                                                      u8"accumulated_storage",
                                                u8"accumulated_storage.back", c},
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_back.current_list_node), u8"projected_storage"},
                                        }},
                                        {{
                                            {u8"id", u8"digit_node_end.accumulated_"
                                                     u8"storage.back"},
                                            {u8"constraint", u8"false"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", u8"#0000FF"},
                                            {u8"style", u8"dashed"},
                                        }}};
                                }
                            } break;
                            case accumulated_storage_node_type_t::digit_node:
                            {
                                auto digit_node = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::digit_node_t::from_accumulated_storage_pointer(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) &>(parameters.datum));
                                if(digit_node->p_accumulated_storage()->front != nullptr)
                                {
                                    auto iterator_projected_storage_front = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(digit_node->p_accumulated_storage()->front));
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"digit_node_" + object_pointer_to_string(digit_node), u8"accumulated_storage.front", c},
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_front.current_list_node), u8"projected_storage"},
                                        }},
                                        {{
                                            {u8"id", u8"digit_node_" + object_pointer_to_string(digit_node) + u8"->accumulated_storage.front"},
                                            {u8"constraint", u8"false"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", u8"#00B4B4"},
                                            {u8"style", u8"dashed"},
                                        }}};
                                }
                                if(digit_node->p_accumulated_storage()->back != nullptr)
                                {
                                    auto iterator_projected_storage_back = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(digit_node->p_accumulated_storage()->back));
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"digit_node_" + object_pointer_to_string(digit_node), u8"accumulated_storage.back", c},
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_back.current_list_node), u8"projected_storage"},
                                        }},
                                        {{
                                            {u8"id", u8"digit_node_" + object_pointer_to_string(digit_node) + u8"->accumulated_storage.back"},
                                            {u8"constraint", u8"false"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", u8"#00B4B4"},
                                            {u8"style", u8"dashed"},
                                        }}};
                                }
                            } break;
                            case accumulated_storage_node_type_t::tree_node:
                            {
                                auto tree_node = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::tree_node_t::from_accumulated_storage_pointer(&const_cast<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(accumulator_diffing_adjacent_element_node_t) &>(parameters.datum));
                                if(tree_node->p_accumulated_storage()->front != nullptr)
                                {
                                    auto iterator_projected_storage_front = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(tree_node->p_accumulated_storage()->front));
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"tree_node_" + object_pointer_to_string(tree_node), u8"accumulated_storage.front", c},
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_front.current_list_node), u8"projected_storage"},
                                        }},
                                        {{
                                            {u8"id", u8"tree_node_" + object_pointer_to_string(tree_node) + u8"->accumulated_storage.front"},
                                            {u8"constraint", u8"false"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", u8"#00B4B4"},
                                            {u8"style", u8"dashed"},
                                        }}};
                                }
                                if(tree_node->p_accumulated_storage()->back != nullptr)
                                {
                                    auto iterator_projected_storage_back = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t::from_projected_storage_pointer(tagged_ptr_bit0_unsetted(tree_node->p_accumulated_storage()->back));
                                    parameters.converter_generated_statements_back_inserter++ = edge_statement_t{
                                        {{
                                            node_id_t{u8"tree_node_" + object_pointer_to_string(tree_node), u8"accumulated_storage.back", c},
                                            node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage_back.current_list_node), u8"projected_storage"},
                                        }},
                                        {{
                                            {u8"id", u8"tree_node_" + object_pointer_to_string(tree_node) + u8"->accumulated_storage.back"},
                                            {u8"constraint", u8"false"},
                                            {u8"tailclip", u8"false"},
                                            {u8"color", u8"#00B4B4"},
                                            {u8"style", u8"dashed"},
                                        }}};
                                }
                            } break;
                            }
                            return html_label_t{fonttable_t{table_t{
                                .BORDER = 0,
                                .CELLBORDER = 1,
                                .CELLSPACING = 0,
                                .PORT = u8"accumulated_storage",
                                .rows = [&]()
                                {
                                    return decltype(table_t::rows){
                                        row_t{{
                                            cell_t{
                                                .BGCOLOR = parameters.datum.front == nullptr ? inactive_cell_color : active_cell_color,
                                                .PORT = u8"accumulated_storage.front",
                                                .content = html_label_t{text_t{{{u8" "}}}},
                                            },
                                            cell_t{
                                                .BGCOLOR = parameters.datum.back == nullptr ? inactive_cell_color : active_cell_color,
                                                .PORT = u8"accumulated_storage.back",
                                                .content = html_label_t{text_t{{{u8" "}}}},
                                            },
                                        }},
                                    };
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

#ifdef __EMSCRIPTEN__
    std::for_each(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).begin(), AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).end(), [&, index = 0](auto iterator_element) mutable
        {
            oss << "it[" << index << "].index(): " << iterator_element.index()<< "; "<< "it[" << index << "].is_end(): " << std::boolalpha<< iterator_element.is_end() << ";" << /*R"(\l)"*/ "\n";
            ++index; });
#else
    std::ranges::for_each(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element), [&, index = 0](auto iterator_element) mutable
        {
            oss << "it[" << index << "].index(): " << iterator_element.index()<< "; "<< "it[" << index << "].is_end(): " << std::boolalpha<< iterator_element.is_end() << ";" << /*R"(\l)"*/ "\n";
            ++index; });
#endif
    if(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).size() >= 2)
    {
        oss << "it[0] <=> it[1]: " << [](std::weak_ordering cmp)
        { return cmp < 0 ? -1 : (cmp > 0 ? 1 : 0); }(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0] <=> AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[1])
            << "; "
            << "it[1] - it[0]: " << (AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[1] - AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0]) << ";" << /*R"(\l)"*/ "\n";
    }
    return oss.str();
}
