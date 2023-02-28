
#ifndef AUGMENTED_DEQUE_EXAMPLE_PREFIX
    #define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) id
#endif

#include "augmented_deque.hpp"
#include "augmented_deque_visualization.hpp"

augmented_containers::augmented_deque_t<
    std::string,
    std::allocator<std::string>,
    std::tuple< //
        std::pair<std::integral_constant<std::size_t, 1>, augmented_containers::augmented_deque_helpers::example_stride1_chunk1_projector_skipped_and_accumulator_plus_t<std::string>>, //
        std::pair<std::integral_constant<std::size_t, 3>, augmented_containers::augmented_deque_helpers::example_chunkgt1_projector_max_element_and_accumulator_min_t<std::string>> //
        > //
    >
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque);
int AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_next_element);
std::vector AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element){
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element(),
    AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element(),
};

std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count)() { return decltype(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque))::sequences_count; }
std::size_t AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count)() { return AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element).size(); }

//iterators
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

//element access
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output)(std::size_t iterator_index, std::string value)
{
    if(AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[iterator_index] != AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element()) *AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[iterator_index] = value;
}

//modifiers
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front)() { AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).push_front((std::ostringstream() << AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_next_element)++).str()); }
void AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back)() { AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).push_back((std::ostringstream() << AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_next_element)++).str()); }
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
            {if(iterator_element_is_front)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element();++index; });
#else
        std::ranges::for_each(iterator_element_is_front_list, [index = 0](bool iterator_element_is_front) mutable
            {if(iterator_element_is_front)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().begin_element();++index; });
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
            {if(iterator_element_is_back)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element();++index; });
#else
        std::ranges::for_each(iterator_element_is_back_list, [index = 0](bool iterator_element_is_back) mutable
            {if(iterator_element_is_back)AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque_iterators_element)[index]=AUGMENTED_DEQUE_EXAMPLE_PREFIXING(augmented_deque).sequence<0>().end_element();++index; });
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
                        return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << std::quoted(parameters.datum)).str().data()))}}}};
                    else if(true)
                        return html_label_t{text_t{{
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data()) << ':' << std::quoted(parameters.datum)).str().data()))},
                        }}};
                    else
                        return html_label_t{text_t{{
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data())).str().data()))},
                            {br_t{.ALIGN = LEFT}},
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << std::quoted(parameters.datum)).str().data()))},
                            {br_t{.ALIGN = LEFT}},
                        }}};
                },
#ifndef __EMSCRIPTEN__
               .projected_and_accumulated_storage_to_string_converter_per_sequence =
#endif
                    std::make_tuple(
                        std::make_pair(
                            std::nullopt,
                            [](auto parameters) -> html_label_t
                            {
                                if(true)
                                    return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << std::quoted(parameters.datum)).str().data()))}}}};
                                else if(true)
                                    return html_label_t{text_t{{
                                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data()) << ':' << std::quoted(parameters.datum)).str().data()))},
                                    }}};
                                else
                                    return html_label_t{text_t{{
                                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data())).str().data()))},
                                        {br_t{.ALIGN = LEFT}},
                                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << std::quoted(parameters.datum)).str().data()))},
                                        {br_t{.ALIGN = LEFT}},
                                    }}};
                            }),
                        std::make_pair(
                            [](auto parameters) -> html_label_t
                            {
                                if(true)
                                    return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << std::quoted(parameters.datum)).str().data()))}}}};
                                else if(true)
                                    return html_label_t{text_t{{
                                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data()) << ':' << std::quoted(parameters.datum)).str().data()))},
                                    }}};
                                else
                                    return html_label_t{text_t{{
                                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data())).str().data()))},
                                        {br_t{.ALIGN = LEFT}},
                                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << std::quoted(parameters.datum)).str().data()))},
                                        {br_t{.ALIGN = LEFT}},
                                    }}};
                            },
                            [](auto parameters) -> html_label_t
                            {
                                if(true)
                                    return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << std::quoted(parameters.datum)).str().data()))}}}};
                                else if(true)
                                    return html_label_t{text_t{{
                                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data()) << ':' << std::quoted(parameters.datum)).str().data()))},
                                    }}};
                                else
                                    return html_label_t{text_t{{
                                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(parameters.member_name.data())).str().data()))},
                                        {br_t{.ALIGN = LEFT}},
                                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << std::quoted(parameters.datum)).str().data()))},
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
                    std::make_tuple(true, true),
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
