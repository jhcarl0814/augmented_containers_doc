
#ifndef AUGMENTED_DEQUE_EXAMPLE_PREFIX
    #define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) id
#endif

#include "augmented_deque.hpp"
#include "augmented_deque_visualization.hpp"
#include <random>
#include <regex>
#include <optional>
#include <cstdint>

std::random_device AUGMENTED_DEQUE_EXAMPLE_PREFIXING(rd); // Will be used to obtain a seed for the random number engine
std::mt19937 AUGMENTED_DEQUE_EXAMPLE_PREFIXING(gen)(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(rd)()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> AUGMENTED_DEQUE_EXAMPLE_PREFIXING(distrib_advance)(0, 10);
std::uniform_int_distribution<> AUGMENTED_DEQUE_EXAMPLE_PREFIXING(distrib_length)(0, 100);

std::optional<std::pair<std::int64_t, std::int64_t>> AUGMENTED_DEQUE_EXAMPLE_PREFIXING(string_to_interval)(std::string const &value)
{
    std::regex interval_regex(R"(\[(-?\d+),(-?\d+)\])", std::regex_constants::ECMAScript);
    if(std::smatch base_match; std::regex_match(value, base_match, interval_regex) && base_match.size() == 3)
    {
        std::ssub_match base_sub_match1 = base_match[1], base_sub_match2 = base_match[2];
        std::int64_t value_int1, value_int2;
        std::istringstream(base_sub_match1.str()) >> value_int1;
        std::istringstream(base_sub_match2.str()) >> value_int2;
        if(value_int1 <= value_int2)
            return std::make_pair(value_int1, value_int2);
        else return std::nullopt;
    }
    else return std::nullopt;
}

struct AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projecting_n_ary_functor_interval_to_upper_endpoint_t)
{
    using projected_storage_t = std::int64_t;
    template<typename it_element_t>
    std::size_t operator()(it_element_t it_element) const { return it_element->second; }
};

augmented_containers::augmented_deque_t<
    std::pair<std::int64_t, std::int64_t>,
    std::allocator<std::pair<std::int64_t, std::int64_t>>,
    std::tuple< //
        std::pair<std::integral_constant<std::size_t, 1>, augmented_containers::augmented_deque_helpers::projector_and_accumulator_wrapping_projecting_and_accumulating_functors_t<AUGMENTED_DEQUE_EXAMPLE_PREFIXING(projecting_n_ary_functor_interval_to_upper_endpoint_t), augmented_containers::augmented_deque_helpers::accumulating_binary_functor_wrapping_homogeneous_binary_functor_t<int, augmented_containers::augmented_deque_helpers::max_t<std::int64_t>>>> //
        > //
    >
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque);
std::int64_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_prev_element), AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_next_element);
std::vector AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element){
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element(),
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element(),
};
std::tuple AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence) = {
    std::vector<decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t>{},
};

std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count)() { return decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count; }
std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count)() { return AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).size(); }

//iterators
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

std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_projected_storage_get_index)(std::size_t I, std::size_t iterator_projected_storage_index)
{
    if(I == 0)
        return std::get<0>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence))[iterator_projected_storage_index].index();
    return static_cast<std::size_t>(-1);
}

//element access
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output)(std::size_t iterator_index, std::string value)
{
    if(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[iterator_index] != AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element() && value.size() >= 1)
    {
        if(auto interval = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(string_to_interval)(value); interval)
            *AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[iterator_index] = *interval;
    }
}

//lookup
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator)(std::size_t I, std::string value)
{
    if(I == 0)
    {
        if(auto interval = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(string_to_interval)(value); interval)
        {
#ifdef __EMSCRIPTEN__
            std::get<0>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence)).clear();
            for(decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t itp : AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).find_by_heap_predicate_generator<0>([&](decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::accumulated_storage_t const &accumulated_string_size)
                    { return static_cast<int>(accumulated_string_size) >= interval->first; }))
            {
                decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t ite = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::to_iterator_element(itp);
                if(ite->first > interval->second)
                    break;
                std::get<0>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence)).push_back(itp);
            }
#else
            std::get<0>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence)) = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).find_by_heap_predicate_generator<0>([&](decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::accumulated_storage_t const &accumulated_string_size)
                                                                                                                           { return static_cast<int>(accumulated_string_size) >= interval->first; }) |
                std::views::take_while([&](decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_projected_storage_t itp)
                    { decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequence_t<0>::iterator_element_t ite = decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::to_iterator_element(itp); return ite->first <= interval->second; }) |
                std::ranges::to<std::vector>();
#endif
        }
    }
}

void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front)()
{
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).push_front(std::make_pair(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_prev_element), AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_prev_element) + AUGMENTED_DEQUE_EXAMPLE_PREFIXING(distrib_length)(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(gen))));
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_prev_element) -= AUGMENTED_DEQUE_EXAMPLE_PREFIXING(distrib_advance)(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(gen));
}
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back)()
{
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).push_back(std::make_pair(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_next_element), AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_next_element) + AUGMENTED_DEQUE_EXAMPLE_PREFIXING(distrib_length)(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(gen))));
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_next_element) += AUGMENTED_DEQUE_EXAMPLE_PREFIXING(distrib_advance)(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(gen));
}
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front)()
{
    if(!AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).empty())
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterator_element_is_front_list;
        std::transform(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).begin(), AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).end(), std::back_inserter(iterator_element_is_front_list), [](auto iterator_element)
            { return iterator_element == AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element(); });
        std::array<std::vector<bool>, decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count> iterator_projected_storage_is_front_list_per_sequence;
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (std::transform(std::get<I>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence)).begin(), std::get<I>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence)).end(), std::back_inserter(std::get<I>(iterator_projected_storage_is_front_list_per_sequence)), [](auto iterator_projected_storage)
                 { return iterator_projected_storage == AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<I>().begin_projected_storage(); }),
                ...);
        }
        (std::make_index_sequence<decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count>());
#else
        std::vector<bool> iterator_element_is_front_list = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element) | std::views::transform([](auto iterator_element)
                                                                                                                                      { return iterator_element == AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element(); }) |
            std::ranges::to<std::vector>();
        std::array<std::vector<bool>, decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count> iterator_projected_storage_is_front_list_per_sequence = [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            return std::array{std::get<I>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence)) | std::views::transform([](auto iterator_projected_storage)
                                                                                                                                             { return iterator_projected_storage == AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<I>().begin_projected_storage(); }) |
                std::ranges::to<std::vector>()...};
        }
        (std::make_index_sequence<decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count>());
#endif
        AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).pop_front();
#ifdef __EMSCRIPTEN__
        std::for_each(iterator_element_is_front_list.begin(), iterator_element_is_front_list.end(), [index = 0](bool iterator_element_is_front) mutable
            {if(iterator_element_is_front)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element();++index; });
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (std::for_each(std::get<I>(iterator_projected_storage_is_front_list_per_sequence).begin(), std::get<I>(iterator_projected_storage_is_front_list_per_sequence).end(), [index = 0](bool iterator_projected_storage_is_front) mutable
                 {if(iterator_projected_storage_is_front)std::get<I>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence))[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<I>().begin_projected_storage();++index; }),
                ...);
        }
        (std::make_index_sequence<decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count>());
#else
        std::ranges::for_each(iterator_element_is_front_list, [index = 0](bool iterator_element_is_front) mutable
            {if(iterator_element_is_front)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element();++index; });
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (std::ranges::for_each(std::get<I>(iterator_projected_storage_is_front_list_per_sequence), [index = 0](bool iterator_projected_storage_is_front) mutable
                 {if(iterator_projected_storage_is_front)std::get<I>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence))[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<I>().begin_projected_storage();++index; }),
                ...);
        }
        (std::make_index_sequence<decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count>());
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
        std::array<std::vector<bool>, decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count> iterator_projected_storage_is_back_list_per_sequence;
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (std::transform(std::get<I>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence)).begin(), std::get<I>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence)).end(), std::back_inserter(std::get<I>(iterator_projected_storage_is_back_list_per_sequence)), [](auto iterator_projected_storage)
                 { return iterator_projected_storage == --augmented_containers::detail::utility::unmove(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<I>().end_projected_storage()); }),
                ...);
        }
        (std::make_index_sequence<decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count>());
#else
        std::vector<bool> iterator_element_is_back_list = AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element) | std::views::transform([](auto iterator_element)
                                                                                                                                     { return iterator_element == --augmented_containers::detail::utility::unmove(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element()); }) |
            std::ranges::to<std::vector>();
        std::array<std::vector<bool>, decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count> iterator_projected_storage_is_back_list_per_sequence = [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            return std::array{std::get<I>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence)) | std::views::transform([](auto iterator_projected_storage)
                                                                                                                                             { return iterator_projected_storage == --augmented_containers::detail::utility::unmove(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<I>().end_projected_storage()); }) |
                std::ranges::to<std::vector>()...};
        }
        (std::make_index_sequence<decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count>());
#endif
        AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).pop_back();
#ifdef __EMSCRIPTEN__
        std::for_each(iterator_element_is_back_list.begin(), iterator_element_is_back_list.end(), [index = 0](bool iterator_element_is_back) mutable
            {if(iterator_element_is_back)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element();++index; });
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (std::for_each(std::get<I>(iterator_projected_storage_is_back_list_per_sequence).begin(), std::get<I>(iterator_projected_storage_is_back_list_per_sequence).end(), [index = 0](bool iterator_projected_storage_is_back) mutable
                 {if(iterator_projected_storage_is_back)std::get<I>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence))[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<I>().end_projected_storage();++index; }),
                ...);
        }
        (std::make_index_sequence<decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count>());
#else
        std::ranges::for_each(iterator_element_is_back_list, [index = 0](bool iterator_element_is_back) mutable
            {if(iterator_element_is_back)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element();++index; });
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (std::ranges::for_each(std::get<I>(iterator_projected_storage_is_back_list_per_sequence), [index = 0](bool iterator_projected_storage_is_back) mutable
                 {if(iterator_projected_storage_is_back)std::get<I>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence))[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<I>().end_projected_storage();++index; }),
                ...);
        }
        (std::make_index_sequence<decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count>());
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
                        return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << '[' << parameters.datum.first << ',' << parameters.datum.second << ']').str().data()))}}}};
                    else if(true)
                        return html_label_t{text_t{{
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data()) << ':' << '[' << parameters.datum.first << ',' << parameters.datum.second << ']').str().data()))},
                        }}};
                    else
                        return html_label_t{text_t{{
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data())).str().data()))},
                            {br_t{.ALIGN = LEFT}},
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << '[' << parameters.datum.first << ',' << parameters.datum.second << ']').str().data()))},
                            {br_t{.ALIGN = LEFT}},
                        }}};
                },
#ifndef __EMSCRIPTEN__
               .projected_and_accumulated_storage_to_string_converter_per_sequence =
#endif
                    std::make_tuple(
                        std::make_pair(
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
                            })),
#ifndef __EMSCRIPTEN__
               .iterators_element =
#endif
                    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element),
#ifndef __EMSCRIPTEN__
               .read_range_per_sequence =
#endif
                    std::make_tuple(true),
#ifndef __EMSCRIPTEN__
               .iterators_projected_storage_per_sequence =
#endif
                    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_projected_storage_per_sequence),
            }))
    {
        result.push_back((std::ostringstream() << graph).str());
    }
    return result;
}
std::string AUGMENTED_DEQUE_EXAMPLE_PREFIXING(additional_info)()
{
    std::ostringstream oss;

#ifdef __EMSCRIPTEN__
    std::for_each(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).begin(), AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).end(), [&, index = 0](auto iterator_element) mutable
        { oss << "it["<<index<<"].index(): " << iterator_element.index()<<"; "<< "it["<<index<<"].is_end(): " <<std::boolalpha<< iterator_element.is_end() <<";"<< /*R"(\l)"*/ "\n"; ++index; });
#else
    std::ranges::for_each(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element), [&, index = 0](auto iterator_element) mutable
        { oss << "it["<<index<<"].index(): " << iterator_element.index()<<"; "<< "it["<<index<<"].is_end(): " <<std::boolalpha<< iterator_element.is_end() <<";"<< /*R"(\l)"*/ "\n"; ++index; });
#endif
    if(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).size() >= 2)
    {
        oss << "it[0] <=> it[1]: " << [](std::weak_ordering cmp)
        { return cmp < 0 ? -1 : (cmp > 0 ? 1 : 0); }(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0] <=> AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[1])
            << "; "
            << "it[1] - it[0]: " << (AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[1] - AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0]) << ";"
            << /*R"(\l)"*/ "\n";
    }
    return oss.str();
}

std::int32_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(front_lower_endpoint)() { return static_cast<std::int32_t>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element()->first); }
std::int32_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(back_upper_endpoint)() { return static_cast<std::int32_t>((--augmented_containers::detail::utility::unmove(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element()))->second); }
std::int32_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(prev_lower_endpoint)()
{
    return
#ifdef __EMSCRIPTEN__
        std::prev
#else
        std::ranges::prev
#endif
        (AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0])
            .is_end()
        ? static_cast<std::int32_t>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_prev_element))
        : static_cast<std::int32_t>(
#ifdef __EMSCRIPTEN__
              std::prev
#else
              std::ranges::prev
#endif
              (AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0])
                  ->first);
}
std::int32_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(next_lower_endpoint)()
{
    return
#ifdef __EMSCRIPTEN__
        std::next
#else
        std::ranges::next
#endif
        (AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0])
            .is_end()
        ? static_cast<std::int32_t>(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_next_element))
        : static_cast<std::int32_t>(
#ifdef __EMSCRIPTEN__
              std::next
#else
              std::ranges::next
#endif
              (AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[0])
                  ->first);
}
