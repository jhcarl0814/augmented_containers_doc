#ifndef AUGMENTED_DEQUE_VISUALIZATION_HPP
#define AUGMENTED_DEQUE_VISUALIZATION_HPP

#include <augmented_containers/augmented_deque.hpp>
#include "ext_infrastructure/ext_graphviz.hpp"
#include <sstream>
#include <iomanip>

namespace augmented_containers
{
    namespace detail
    {
        namespace visualization
        {
#ifndef AUGMENTED_CONTAINERS_VISUALIZATION_COMMON
    #define AUGMENTED_CONTAINERS_VISUALIZATION_COMMON
            template<typename T>
            struct print_function_pointer_t
            {
                T p;
            };
            template<typename OutputStream, typename T>
            OutputStream &&operator<<(OutputStream &&os, print_function_pointer_t<T> print_pointer)
            {
                std::ranges::for_each(reinterpret_cast<std::byte const(&)[sizeof(T)]>(print_pointer.p), [&](std::byte const &b)
                    { os << "0x" << std::hex << std::setw(2) << std::setfill('0') << (int)b << std::dec << std::setw(0) << std::setfill(' '); });
                return std::forward<OutputStream>(os);
            }
            template<typename T>
            struct print_object_pointer_t
            {
                T p;
            };
    #if __cpp_deduction_guides >= 201907L
    #else
            template<typename T>
            print_object_pointer_t(T) -> print_object_pointer_t<T>;
    #endif
            template<typename OutputStream, typename T>
            OutputStream &&operator<<(OutputStream &&os, print_object_pointer_t<T> print_pointer)
            {
                os << "0x" << std::hex << std::setw(2 * sizeof(T)) << std::setfill('0') << reinterpret_cast<uintptr_t>(print_pointer.p) << std::dec << std::setw(0) << std::setfill(' ');
                return std::forward<OutputStream>(os);
            }

            //    using namespace std::literals::string_literals;
            static constexpr char8_t active_cell_color[] = u8"#ffffffaa" /*s*/;
            static constexpr char8_t inactive_cell_color[] = u8"#ccccccaa" /*s*/;
            std::u8string index_to_string(auto i)
            {
                return std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << i).str().data()));
            };
            std::u8string object_pointer_to_string(auto p)
            {
                return std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << print_object_pointer_t{p}).str().data()));
            };
            dot::text_t not_member_to_text(std::u8string member_name, auto &&value)
            {
                using namespace dot;
                if(true)
                    return text_t{{
                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << value).str().data()))},
                    }};
                else if(true)
                    return text_t{{
                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(member_name.data()) << ':' << value).str().data()))},
                    }};
                else
                    return text_t{{
                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(member_name.data())).str().data()))},
                        {br_t{.ALIGN = LEFT}},
                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << value).str().data()))},
                        {br_t{.ALIGN = LEFT}},
                    }};
            };
            dot::text_t member_to_text(std::u8string member_name, auto &&value)
            {
                using namespace dot;
                if(true)
                    return text_t{{
                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << value).str().data()))},
                    }};
                else if(true)
                    return text_t{{
                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << '.' << reinterpret_cast<char const *>(member_name.data()) << '=' << value).str().data()))},
                    }};
                else
                    return text_t{{
                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << reinterpret_cast<char const *>(member_name.data())).str().data()))},
                        {br_t{.ALIGN = LEFT}},
                        {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << value).str().data()))},
                        {br_t{.ALIGN = LEFT}},
                    }};
            };
            dot::text_t pointer_member_text_to_space(dot::text_t text)
            {
                using namespace dot;
                if(true)
                    return text_t{{{u8" "}}};
                else
                    return text;
            };
            dot::text_t pointer_title_text_to_title_only(std::u8string title, std::u8string text)
            {
                using namespace dot;
                if(true)
                    return text_t{{{title}}};
                else
                    return text_t{{{title + u8' '}, {text}}};
            };
#endif // AUGMENTED_CONTAINERS_VISUALIZATION_COMMON

            namespace augmented_deque
            {
                enum class accumulated_storage_node_type_e { uninitialized,
                    digit_node,
                    tree_node,
                    digit_node_end_accumulated_storage,
                    read_range };

                template<typename datum_t, typename converter_generated_statements_back_inserter_t>
                struct to_string_converter_parameters_t
                {
                    std::u8string const &member_name;
                    datum_t const &datum;
                    converter_generated_statements_back_inserter_t converter_generated_statements_back_inserter;
                    accumulated_storage_node_type_e accumulated_storage_node_type;
                };
#if __cpp_deduction_guides >= 201907L
#else
                template<typename datum_t, typename converter_generated_statements_back_inserter_t>
                to_string_converter_parameters_t(std::u8string const &, datum_t const &, converter_generated_statements_back_inserter_t, accumulated_storage_node_type_e) -> to_string_converter_parameters_t<datum_t, converter_generated_statements_back_inserter_t>;
                template<typename datum_t, typename converter_generated_statements_back_inserter_t>
                to_string_converter_parameters_t(std::u8string const &, datum_t const &, converter_generated_statements_back_inserter_t) -> to_string_converter_parameters_t<datum_t, converter_generated_statements_back_inserter_t>;
#endif

                template<typename element_to_string_converter_t, typename projected_and_accumulated_storage_to_string_converter_per_sequence_t, typename iterators_element_t, typename read_range_per_sequence_t, typename iterators_projected_storage_per_sequence_t = std::nullopt_t>
                struct to_graphs_parameters_t
                {
                    element_to_string_converter_t element_to_string_converter;
                    projected_and_accumulated_storage_to_string_converter_per_sequence_t projected_and_accumulated_storage_to_string_converter_per_sequence;
                    iterators_element_t iterators_element;
                    read_range_per_sequence_t read_range_per_sequence;
                    iterators_projected_storage_per_sequence_t iterators_projected_storage_per_sequence = std::nullopt;
                };
#if __cpp_deduction_guides >= 201907L
#else
                template<typename... T>
                to_graphs_parameters_t(T...) -> to_graphs_parameters_t<T...>;
#endif
            } // namespace augmented_deque
        } // namespace visualization
    } // namespace detail

    template<typename element_t, typename allocator_element_t, typename config_t, typename... to_graphs_parameters_t_parameters_t>
    std::vector<dot::graph_t> to_graphs(
        augmented_deque_t<element_t, allocator_element_t, config_t> const &augmented_deque,
        detail::visualization::augmented_deque::to_graphs_parameters_t<to_graphs_parameters_t_parameters_t...> to_graphs_parameters)
    {
        using namespace dot;
        using namespace detail::language;
        using namespace detail::visualization;
        using namespace detail::visualization::augmented_deque;

        return [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            return std::vector<graph_t>{[&augmented_deque, &stride1_sequence = augmented_deque.template sequence<0>(), &sequence = augmented_deque.template sequence<I>(), &to_graphs_parameters]()
                {
                    using stride1_sequence_t = typename std::remove_cvref_t<decltype(augmented_deque)>::template sequence_t<0>;
                    using sequence_t = typename std::remove_cvref_t<decltype(augmented_deque)>::template sequence_t<I>;
                    //                typename augmented_deque_t<T, Allocator, config_t>::template sequence_t<I> &sequence = augmented_deque.template sequence<I>();

                    constexpr bool generating_title = false;
                    constexpr bool generating_list_node_front_and_back = false;
                    constexpr bool print_stride1_projected_storage_td_even_if_does_not_exist = false;

                    std::vector<std::variant<node_statement_t, edge_statement_t, attr_statement_t, attr_t, subgraph_t>> converter_generated_statements;

                    node_statement_t sequence_members_render_from_left_to_right_node{{u8"sequence_members_render_from_left_to_right"},
                        {{
                            {u8"id", u8"sequence_members_render_from_left_to_right"},
                            {u8"ordering", u8"out"},
                        }}};
                    if constexpr(I == 0)
                    {
                        sequence_members_render_from_left_to_right_node.attributes.back().push_back(attr_t{
                            u8"label", std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "augmented_deque.sequence<" << I << ">()"
                                           //                                                                                                             << R"( { )" //<< R"(\l)"
                                           //                                                                                                             << ".list_node_count(): " << sequence.list_node_count() << ","
                                           //                                                                                                             << R"( })" // << R"(\l)"
                                           )
                                                                                           .str()
                                                                                           .data()))});
                    }
                    else
                    {
                        sequence_members_render_from_left_to_right_node.attributes.back().push_back(attr_t{
                            u8"label", std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "augmented_deque.sequence<" << I << ">()"
                                           //                                                                                                             << R"( { )" //<< R"(\l)"
                                           //                                                                                                             << ".list_node_count(): " << sequence.list_node_count() << ","
                                           //                                                                                                             << R"( )" //<< R"(\l)"
                                           //                                                                                                             << ".list_front_element_count(): " << sequence.list_front_element_count() << ","
                                           //                                                                                                             << R"( )" //<< R"(\l)"
                                           //                                                                                                             << ".list_back_element_count(): " << sequence.list_back_element_count() << ","
                                           //                                                                                                             << R"( })" //<< R"(\l)"
                                           )
                                                                                           .str()
                                                                                           .data()))});
                    }
                    std::vector<edge_statement_t> sequence_members_render_from_left_to_right_edges;
                    if constexpr(generating_list_node_front_and_back)
                        sequence_members_render_from_left_to_right_edges.push_back(edge_statement_t{{{
                                                                                                        node_id_t{u8"sequence_members_render_from_left_to_right"},
                                                                                                        node_id_t{u8"list_node_front"},
                                                                                                    }},
                            {{
                                {u8"id", u8"sequence_members_render_from_left_to_right->list_node_front"},
                                {u8"constraint", u8"true"},
                                {u8"tailclip", u8"false"},
                                {u8"color", u8"transparent"},
                            }}});
                    sequence_members_render_from_left_to_right_edges.push_back(edge_statement_t{{{
                                                                                                    node_id_t{u8"sequence_members_render_from_left_to_right"},
                                                                                                    node_id_t{u8"digit_front"},
                                                                                                }},
                        {{
                            {u8"id", u8"sequence_members_render_from_left_to_right->digit_front"},
                            {u8"constraint", u8"true"},
                            {u8"tailclip", u8"false"},
                            {u8"color", u8"transparent"},
                        }}});
                    sequence_members_render_from_left_to_right_edges.push_back(edge_statement_t{{{
                                                                                                    node_id_t{u8"sequence_members_render_from_left_to_right"},
                                                                                                    node_id_t{u8"digit_middle"},
                                                                                                }},
                        {{
                            {u8"id", u8"sequence_members_render_from_left_to_right->digit_middle"},
                            {u8"constraint", u8"true"},
                            {u8"tailclip", u8"false"},
                            {u8"color", u8"transparent"},
                        }}});
                    sequence_members_render_from_left_to_right_edges.push_back(edge_statement_t{{{
                                                                                                    node_id_t{u8"sequence_members_render_from_left_to_right"},
                                                                                                    node_id_t{u8"digit_back"},
                                                                                                }},
                        {{
                            {u8"id", u8"sequence_members_render_from_left_to_right->digit_back"},
                            {u8"constraint", u8"true"},
                            {u8"tailclip", u8"false"},
                            {u8"color", u8"transparent"},
                        }}});
                    if constexpr(generating_list_node_front_and_back)
                        sequence_members_render_from_left_to_right_edges.push_back(edge_statement_t{{{
                                                                                                        node_id_t{u8"sequence_members_render_from_left_to_right"},
                                                                                                        node_id_t{u8"list_node_back"},
                                                                                                    }},
                            {{
                                {u8"id", u8"sequence_members_render_from_left_to_right->list_node_back"},
                                {u8"constraint", u8"true"},
                                {u8"tailclip", u8"false"},
                                {u8"color", u8"transparent"},
                            }}});

                    subgraph_t sequence_members{
                        .name = std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "augmented_deque.sequence<" << I << ">()").str().data())),
                        .statements = {
                            attr_t{u8"label", u8""},
                            attr_t{u8"id", u8"sequence_members"},

                            attr_t{u8"cluster", u8"false"},
                            attr_t{u8"rank", u8"same"},
                        },
                    };
                    subgraph_t sequence_members_digit_end_accumulated_storage{
                        .name = std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "augmented_deque.sequence<" << I << ">() sequence_members_digit_end_accumulated_storage").str().data())),
                        .statements = {
                            attr_t{u8"label", u8""},
                            attr_t{u8"id", u8"sequence_members_digit_end_accumulated_storage"},

                            attr_t{u8"cluster", u8"false"},
                            attr_t{u8"rank", u8"sink"},
                        },
                    };
                    if constexpr(generating_list_node_front_and_back)
                        sequence_members.statements.push_back(node_statement_t{{u8"list_node_front"},
                            {{
                                {u8"id", u8"list_node_front"},
                                {u8"label", html_label_t{fonttable_t{table_t{
                                                .BORDER = 0,
                                                .CELLBORDER = 1,
                                                .CELLSPACING = 0,
                                                .rows = [&]()
                                                { return decltype(table_t::rows){
                                                      row_t{{
                                                          cell_t{
                                                              .BGCOLOR = sequence_t::navigator_t::untagged_next_or_tagged_end(sequence.list_node_end) == sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                              .content = html_label_t{pointer_member_text_to_space(not_member_to_text(u8"list_node_front", tagged_ptr_bit0_unsetted(sequence.list_node_end)->next))},
                                                          },
                                                      }},
                                                  }; }(),
                                            }}}},
                            }}});
                    sequence_members.statements.push_back(node_statement_t{{u8"digit_front"},
                        {{
                            {u8"id", u8"digit_front"},
                            {u8"label", html_label_t{fonttable_t{table_t{
                                            .BORDER = 0,
                                            .CELLBORDER = 1,
                                            .CELLSPACING = 0,
                                            .rows = [&]()
                                            { return decltype(table_t::rows){
                                                  row_t{{
                                                      cell_t{
                                                          .BGCOLOR = sequence_t::navigator_t::untagged_next_or_tagged_end(sequence.digit_node_end) == sequence.digit_node_end ? inactive_cell_color : active_cell_color,
                                                          .content = html_label_t{pointer_member_text_to_space(not_member_to_text(u8"digit_front", sequence.digit_front()))},
                                                      },
                                                  }},
                                              }; }(),
                                        }}}},
                        }}});
                    sequence_members.statements.push_back(node_statement_t{{u8"digit_middle"},
                        {{
                            {u8"id", u8"digit_middle"},
                            {u8"ordering", u8"out"},
                            {u8"label", html_label_t{fonttable_t{table_t{
                                            .BORDER = 0,
                                            .CELLBORDER = 1,
                                            .CELLSPACING = 0,
                                            .rows = [&]()
                                            { return decltype(table_t::rows){
                                                  row_t{{
                                                      cell_t{
                                                          .BGCOLOR = sequence.digit_middle() == tagged_ptr_bit0_unsetted(sequence.digit_node_end) ? inactive_cell_color : active_cell_color,
                                                          .content = html_label_t{pointer_member_text_to_space(not_member_to_text(u8"digit_middle", sequence.digit_middle()))},
                                                      },
                                                  }},
                                              }; }(),
                                        }}}},
                        }}});
                    sequence_members.statements.push_back(node_statement_t{{u8"digit_back"},
                        {{
                            {u8"id", u8"digit_back"},
                            {u8"label", html_label_t{fonttable_t{table_t{
                                            .BORDER = 0,
                                            .CELLBORDER = 1,
                                            .CELLSPACING = 0,
                                            .rows = [&]()
                                            { return decltype(table_t::rows){
                                                  row_t{{
                                                      cell_t{
                                                          .BGCOLOR = sequence_t::navigator_t::untagged_prev_or_tagged_end(sequence.digit_node_end) == sequence.digit_node_end ? inactive_cell_color : active_cell_color,
                                                          .content = html_label_t{pointer_member_text_to_space(not_member_to_text(u8"digit_back", sequence.digit_back()))},
                                                      },
                                                  }},
                                              }; }(),
                                        }}}},
                        }}});
                    if constexpr(generating_list_node_front_and_back)
                        sequence_members.statements.push_back(node_statement_t{{u8"list_node_back"},
                            {{
                                {u8"id", u8"list_node_back"},
                                {u8"label", html_label_t{fonttable_t{table_t{
                                                .BORDER = 0,
                                                .CELLBORDER = 1,
                                                .CELLSPACING = 0,
                                                .rows = [&]()
                                                { return decltype(table_t::rows){
                                                      row_t{{
                                                          cell_t{
                                                              .BGCOLOR = sequence_t::navigator_t::untagged_prev_or_tagged_end(sequence.list_node_end) == sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                              .content = html_label_t{pointer_member_text_to_space(not_member_to_text(u8"list_node_back", tagged_ptr_bit0_unsetted(sequence.list_node_end)->prev))},
                                                          },
                                                      }},
                                                  }; }(),
                                            }}}},
                            }}});
                    if constexpr(!std::is_same_v<typename sequence_t::accumulated_storage_t, void>)
                    {
                        sequence_members_digit_end_accumulated_storage.statements.push_back(node_statement_t{{u8"digit_node_end.accumulated_storage"},
                            {{
                                {u8"id", u8"digit_node_end.accumulated_storage"},
                                {u8"label", html_label_t{fonttable_t{table_t{
                                                .BORDER = 0,
                                                .CELLBORDER = 1,
                                                .CELLSPACING = 0,
                                                .rows = [&]()
                                                { return decltype(table_t::rows){
                                                      row_t{{
                                                          cell_t{
                                                              .BGCOLOR = active_cell_color,
                                                              .COLSPAN = 6,
                                                              .content = std::get<1>(std::get<I>(to_graphs_parameters.projected_and_accumulated_storage_to_string_converter_per_sequence))(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                  .member_name =
#endif
                                                                      u8"accumulated_storage",
#ifndef __EMSCRIPTEN__
                                                                  .datum =
#endif
                                                                      *tagged_ptr_bit0_unsetted(sequence.digit_node_end)->p_accumulated_storage(),
#ifndef __EMSCRIPTEN__
                                                                  .converter_generated_statements_back_inserter =
#endif
                                                                      std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                  .accumulated_storage_node_type =
#endif
                                                                      accumulated_storage_node_type_e::digit_node_end_accumulated_storage,
                                                              }),
                                                          },
                                                      }},
                                                  }; }(),
                                            }}}},
                            }}});
                        if(std::get<I>(to_graphs_parameters.read_range_per_sequence) && to_graphs_parameters.iterators_element.size() >= 2 && to_graphs_parameters.iterators_element[0] <= to_graphs_parameters.iterators_element[1])
                        {
                            sequence_members_digit_end_accumulated_storage.statements.push_back(node_statement_t{{u8"read_range"},
                                {{
                                    {u8"id", u8"read_range"},
                                    {u8"label", std::get<1>(std::get<I>(to_graphs_parameters.projected_and_accumulated_storage_to_string_converter_per_sequence))(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                    .member_name =
#endif
                                                        u8"read_range(it[0], it[1])",
#ifndef __EMSCRIPTEN__
                                                    .datum =
#endif
                                                        augmented_deque.template read_range<I>(to_graphs_parameters.iterators_element[0], to_graphs_parameters.iterators_element[1]),
#ifndef __EMSCRIPTEN__
                                                    .converter_generated_statements_back_inserter =
#endif
                                                        std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                    .accumulated_storage_node_type =
#endif
                                                        accumulated_storage_node_type_e::read_range,
                                                })},
                                }}});
                        }
                    }
                    std::vector<edge_statement_t> sequence_members_edges;
                    if constexpr(generating_list_node_front_and_back)
                        if(sequence_t::navigator_t::untagged_next_or_tagged_end(sequence.list_node_end) != sequence.list_node_end)
                            sequence_members_edges.push_back(edge_statement_t{{{
                                                                                  node_id_t{u8"list_node_front", std::nullopt, c},
                                                                                  node_id_t{u8"list_node_" + object_pointer_to_string(sequence_t::list_node_t::untagged_next(sequence.list_node_end))},
                                                                              }},
                                {{
                                    {u8"id", u8"sequence->list_node_front"},
                                    {u8"constraint", u8"false"},
                                    {u8"tailclip", u8"false"},
                                    {u8"style", u8"dashed"},
                                }}});
                    if(sequence_t::navigator_t::untagged_next_or_tagged_end(sequence.digit_node_end) != sequence.digit_node_end)
                        sequence_members_edges.push_back(edge_statement_t{{{
                                                                              node_id_t{u8"digit_front", std::nullopt, c},
                                                                              node_id_t{u8"digit_node_" + object_pointer_to_string(sequence.digit_front())},
                                                                          }},
                            {{
                                {u8"id", u8"sequence->digit_front"},
                                {u8"style", tagged_ptr_bit0_is_setted(tagged_ptr_bit0_unsetted(sequence.digit_node_end)->next) ? u8"dashed" : u8"solid"},
                                {u8"constraint", u8"true"},
                                {u8"tailclip", u8"false"},
                            }}});
                    if(sequence_t::navigator_t::untagged_prev_or_tagged_end(sequence.digit_node_end) != sequence.digit_node_end)
                        sequence_members_edges.push_back(edge_statement_t{{{
                                                                              node_id_t{u8"digit_back", std::nullopt, c},
                                                                              node_id_t{u8"digit_node_" + object_pointer_to_string(sequence.digit_back())},
                                                                          }},
                            {{
                                {u8"id", u8"sequence->digit_back"},
                                {u8"style", tagged_ptr_bit0_is_setted(tagged_ptr_bit0_unsetted(sequence.digit_node_end)->prev) ? u8"dashed" : u8"solid"},
                                {u8"constraint", u8"true"},
                                {u8"tailclip", u8"false"},
                            }}});
                    if constexpr(generating_list_node_front_and_back)
                        if(sequence_t::navigator_t::untagged_prev_or_tagged_end(sequence.list_node_end) != sequence.list_node_end)
                            sequence_members_edges.push_back(edge_statement_t{{{
                                                                                  node_id_t{u8"list_node_back", std::nullopt, c},
                                                                                  node_id_t{u8"list_node_" + object_pointer_to_string(sequence_t::list_node_t::untagged_prev(sequence.list_node_end))},
                                                                              }},
                                {{
                                    {u8"id", u8"sequence->list_node_back"},
                                    {u8"constraint", u8"false"},
                                    {u8"tailclip", u8"false"},
                                    {u8"style", u8"dashed"},
                                }}});

                    std::vector<node_statement_t> digit_nodes;
                    std::vector<edge_statement_t> digit_node_edges;
                    subgraph_t digit_nodes_same_rank{.statements = {
                                                         attr_t{u8"rank", u8"same"},
                                                     }};
                    std::vector<node_statement_t> tree_nodes;
                    std::vector<edge_statement_t> tree_node_edges;
                    std::vector<node_statement_t> list_nodes;
                    std::vector<edge_statement_t> list_node_edges;
                    std::vector<node_statement_t> iterator_element_nodes;
                    std::vector<edge_statement_t> iterator_element_edges;
                    std::vector<node_statement_t> iterator_projected_storage_nodes;
                    std::vector<edge_statement_t> iterator_projected_storage_edges;
                    subgraph_t list_nodes_same_rank{.statements = {
                                                        attr_t{u8"rank", u8"same"},
                                                    }};
                    subgraph_t stride1_list_nodes_same_rank{.statements = {
                                                                attr_t{u8"rank", u8"same"},
                                                            }};

                    using tree_node_t = typename sequence_t::tree_node_t;
                    std::function<void(typename sequence_t::tree_node_t *)> tree_node_recursive = //
                        [&](tree_node_t *p_tree_node)
                    {
                        assert(p_tree_node->parent != nullptr);
                        tree_node_edges.push_back(edge_statement_t{{{
                                                                       node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"parent", c},
                                                                       node_id_t{(tagged_ptr_bit0_is_setted(p_tree_node->parent) ? u8"digit_node_" : u8"tree_node_") + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->parent))},
                                                                   }},
                            {{
                                {u8"id", u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"->parent"},
                                {u8"style", tagged_ptr_bit0_is_setted(p_tree_node->parent) ? u8"dashed" : u8"solid"},
                                {u8"constraint", u8"false"},
                                {u8"tailclip", u8"false"},
                            }}});
                        assert(p_tree_node->child_left != nullptr);
                        tree_node_edges.push_back(edge_statement_t{{{
                                                                       node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"child_left", c},
                                                                       node_id_t{(tagged_ptr_bit0_is_setted(p_tree_node->child_left) ? u8"list_node_" : u8"tree_node_") + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->child_left))},
                                                                   }},
                            {{
                                {u8"id", u8"parent->" + ((tagged_ptr_bit0_is_setted(p_tree_node->child_left) ? u8"list_node_" : u8"tree_node_") + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->child_left)))},
                                {u8"style", tagged_ptr_bit0_is_setted(p_tree_node->child_left) ? u8"dashed" : u8"solid"},
                                {u8"constraint", u8"true"},
                                {u8"tailclip", u8"false"},
                            }}});
                        assert(p_tree_node->child_right != nullptr);
                        tree_node_edges.push_back(edge_statement_t{{{
                                                                       node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"child_right", c},
                                                                       node_id_t{(tagged_ptr_bit0_is_setted(p_tree_node->child_right) ? u8"list_node_" : u8"tree_node_") + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->child_right))},
                                                                   }},
                            {{
                                {u8"id", u8"parent->" + ((tagged_ptr_bit0_is_setted(p_tree_node->child_right) ? u8"list_node_" : u8"tree_node_") + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->child_right)))},
                                {u8"style", tagged_ptr_bit0_is_setted(p_tree_node->child_right) ? u8"dashed" : u8"solid"},
                                {u8"constraint", u8"true"},
                                {u8"tailclip", u8"false"},
                            }}});

                        tree_nodes.push_back(node_statement_t{{u8"tree_node_" + object_pointer_to_string(p_tree_node)},
                            {{
                                {u8"id", u8"tree_node_" + object_pointer_to_string(p_tree_node)},
                                {u8"label", html_label_t{fonttable_t{table_t{
                                                .BORDER = 0,
                                                .CELLBORDER = 1,
                                                .CELLSPACING = 0,
                                                .rows = [&]()
                                                {
                                                    decltype(table_t::rows) result;
                                                    if constexpr(generating_title)
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                                .COLSPAN = 4,
                                                                .content = html_label_t{pointer_title_text_to_title_only(u8"tree_node", object_pointer_to_string(p_tree_node))},
                                                            },
                                                        }});
                                                    result.push_back(
                                                        row_t{{
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 2,
                                                                .PORT = u8"parent",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"parent", print_object_pointer_t{p_tree_node->parent}))},
                                                            },
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                        }});
                                                    if constexpr(!std::is_same_v<typename sequence_t::accumulated_storage_t, void>)
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 4,
                                                                .content = std::get<1>(std::get<I>(to_graphs_parameters.projected_and_accumulated_storage_to_string_converter_per_sequence))(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"accumulated_storage",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        *p_tree_node->p_accumulated_storage(),
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                    .accumulated_storage_node_type =
#endif
                                                                        accumulated_storage_node_type_e::tree_node,
                                                                }),
                                                            },
                                                        }});
                                                    result.push_back(row_t{{
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 2,
                                                            .PORT = u8"child_left",
                                                            .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"child_left", print_object_pointer_t{p_tree_node->child_left}))},
                                                        },
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 2,
                                                            .PORT = u8"child_right",
                                                            .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"child_right", print_object_pointer_t{p_tree_node->child_right}))},
                                                        },
                                                    }});
                                                    return result; //
                                                }(),
                                            }}}},
                            }}});

                        if(assert(p_tree_node->child_left != nullptr), !tagged_ptr_bit0_is_setted(p_tree_node->child_left))
                            tree_node_recursive(p_tree_node->child_left);
                        if(assert(p_tree_node->child_right != nullptr), !tagged_ptr_bit0_is_setted(p_tree_node->child_right))
                            tree_node_recursive(p_tree_node->child_right);
                    };

                    for(auto p_digit_node_navigator = sequence_t::navigator_t::untagged_next_or_tagged_end(sequence.digit_node_end); p_digit_node_navigator != sequence.digit_node_end; p_digit_node_navigator = p_digit_node_navigator->next)
                    {
                        auto p_digit_node = static_cast<typename sequence_t::digit_node_t *>(p_digit_node_navigator);

                        if(p_digit_node->prev != sequence.digit_node_end)
                            digit_node_edges.push_back(edge_statement_t{{{
                                                                            node_id_t{u8"digit_node_" + object_pointer_to_string(p_digit_node), u8"prev", c},
                                                                            node_id_t{u8"digit_node_" + object_pointer_to_string(p_digit_node->prev)},
                                                                        }},
                                {{
                                    {u8"id", u8"digit_node_" + object_pointer_to_string(p_digit_node) + u8"->prev"},
                                    {u8"constraint", u8"false"},
                                    {u8"tailclip", u8"false"},
                                }}});

                        if(p_digit_node->next != sequence.digit_node_end)
                            digit_node_edges.push_back(edge_statement_t{{{
                                                                            node_id_t{u8"digit_node_" + object_pointer_to_string(p_digit_node), u8"next", c},
                                                                            node_id_t{u8"digit_node_" + object_pointer_to_string(p_digit_node->next)},
                                                                        }},
                                {{
                                    {u8"id", u8"digit_node_" + object_pointer_to_string(p_digit_node) + u8"->next"},
                                    {u8"constraint", u8"false"},
                                    {u8"tailclip", u8"false"},
                                }}});

                        assert(p_digit_node->tree_left != nullptr || p_digit_node->tree_right != nullptr);
                        if(p_digit_node->tree_left != nullptr)
                            digit_node_edges.push_back(edge_statement_t{{{
                                                                            node_id_t{u8"digit_node_" + object_pointer_to_string(p_digit_node), u8"tree_left", c},
                                                                            node_id_t{(tagged_ptr_bit0_is_setted(p_digit_node->tree_left) ? u8"list_node_" : u8"tree_node_") + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_digit_node->tree_left))},
                                                                        }},
                                {{
                                    {u8"id", u8"parent->" + ((tagged_ptr_bit0_is_setted(p_digit_node->tree_left) ? u8"list_node_" : u8"tree_node_") + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_digit_node->tree_left)))},
                                    {u8"style", tagged_ptr_bit0_is_setted(p_digit_node->tree_left) ? u8"dashed" : u8"solid"},
                                    {u8"constraint", u8"true"},
                                    {u8"tailclip", u8"false"},
                                }}});
                        if(p_digit_node->tree_right != nullptr)
                            digit_node_edges.push_back(edge_statement_t{{{
                                                                            node_id_t{u8"digit_node_" + object_pointer_to_string(p_digit_node), u8"tree_right", c},
                                                                            node_id_t{(tagged_ptr_bit0_is_setted(p_digit_node->tree_right) ? u8"list_node_" : u8"tree_node_") + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_digit_node->tree_right))},
                                                                        }},
                                {{
                                    {u8"id", u8"parent->" + ((tagged_ptr_bit0_is_setted(p_digit_node->tree_right) ? u8"list_node_" : u8"tree_node_") + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_digit_node->tree_right)))},
                                    {u8"style", tagged_ptr_bit0_is_setted(p_digit_node->tree_right) ? u8"dashed" : u8"solid"},
                                    {u8"constraint", u8"true"},
                                    {u8"tailclip", u8"false"},
                                }}});

                        //sequence use cluster
                        sequence_members_edges.push_back(
                            edge_statement_t{{{
                                                 node_id_t{u8"digit_middle", std::nullopt, c},
                                                 node_id_t{u8"digit_node_" + object_pointer_to_string(p_digit_node)},
                                             }},
                                {{
                                    {u8"constraint", u8"true"},
                                    {u8"tailclip", u8"false"},
                                }}});
                        if(p_digit_node != sequence.digit_middle())
                        {
                            sequence_members_edges.back().attributes.back().push_back({u8"color", u8"transparent"});
                        }
                        else
                        {
                            sequence_members_edges.back().attributes.back().push_back({u8"id", u8"sequence->digit_middle"});
                            sequence_members_edges.back().attributes.back().push_back({u8"style", tagged_ptr_bit0_is_setted(tagged_ptr_bit0_unsetted(sequence.digit_node_end)->middle) ? u8"dashed" : u8"solid"});
                        }

                        digit_nodes_same_rank.statements.push_back(node_statement_t{{u8"digit_node_" + object_pointer_to_string(p_digit_node)}});
                        digit_nodes.push_back(node_statement_t{{u8"digit_node_" + object_pointer_to_string(p_digit_node)},
                            {{
                                {u8"id", u8"digit_node_" + object_pointer_to_string(p_digit_node)},
                                {u8"label", html_label_t{fonttable_t{table_t{
                                                .BORDER = 0,
                                                .CELLBORDER = 1,
                                                .CELLSPACING = 0,
                                                .rows = [&]()
                                                {
                                                    decltype(table_t::rows) result;
                                                    if constexpr(generating_title)
                                                        result.push_back(
                                                            row_t{{
                                                                cell_t{
                                                                    .COLOR = u8"transparent",
                                                                    .COLSPAN = 6,
                                                                    .content = html_label_t{pointer_title_text_to_title_only(u8"digit_node", object_pointer_to_string(p_digit_node))},
                                                                },
                                                            }});
                                                    result.push_back(
                                                        row_t{{
                                                            cell_t{
                                                                .BGCOLOR = p_digit_node->prev == sequence.digit_node_end ? inactive_cell_color : active_cell_color,
                                                                .COLSPAN = 2,
                                                                .PORT = u8"prev",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"prev", print_object_pointer_t{p_digit_node->prev}))},
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 2,
                                                                .content = /*html_label_t{member_to_text(u8"digit_position", p_digit_node->digit_position)}*/ [&]()
                                                                { return html_label_t{text_t{{
                                                                      textitem_t{std::make_pair(font_t{.COLOR = u8"#00000060"}, text_t{{textitem_t{u8"2"}}})},
                                                                      textitem_t{std::make_pair(sup_t{}, text_t{{{index_to_string(p_digit_node->digit_position)}}})},
                                                                      textitem_t{std::make_pair(font_t{.COLOR = u8"#00000060"}, text_t{{textitem_t{u8"*" + index_to_string((p_digit_node->tree_left != nullptr) + (p_digit_node->tree_right != nullptr))}}})},
                                                                  }}}; }(),
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = p_digit_node->next == sequence.digit_node_end ? inactive_cell_color : active_cell_color,
                                                                .COLSPAN = 2,
                                                                .PORT = u8"next",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{p_digit_node->next}))},
                                                            },
                                                        }});
                                                    if constexpr(!std::is_same_v<typename sequence_t::accumulated_storage_t, void>)
                                                    {
                                                        if(p_digit_node != sequence.digit_middle())
                                                            result.push_back(row_t{{
                                                                cell_t{
                                                                    .BGCOLOR = active_cell_color,
                                                                    .COLSPAN = 6,
                                                                    .content = std::get<1>(std::get<I>(to_graphs_parameters.projected_and_accumulated_storage_to_string_converter_per_sequence))(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                        .member_name =
#endif
                                                                            u8"accumulated_storage",
#ifndef __EMSCRIPTEN__
                                                                        .datum =
#endif
                                                                            *p_digit_node->p_accumulated_storage(),
#ifndef __EMSCRIPTEN__
                                                                        .converter_generated_statements_back_inserter =
#endif
                                                                            std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                        .accumulated_storage_node_type =
#endif
                                                                            accumulated_storage_node_type_e::digit_node,
                                                                    }),
                                                                },
                                                            }});
                                                        else
                                                            result.push_back(row_t{{
                                                                cell_t{
                                                                    .BGCOLOR = inactive_cell_color,
                                                                    .COLSPAN = 6,
                                                                    .content = html_label_t{text_t{{{u8" "}}}},
                                                                },
                                                            }});
                                                    }
                                                    result.push_back(
                                                        row_t{{
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = p_digit_node->tree_left == nullptr ? inactive_cell_color : active_cell_color,
                                                                .COLSPAN = 2,
                                                                .PORT = u8"tree_left",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"tree_left", print_object_pointer_t{p_digit_node->tree_left}))},
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = p_digit_node->tree_right == nullptr ? inactive_cell_color : active_cell_color,
                                                                .COLSPAN = 2,
                                                                .PORT = u8"tree_right",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"tree_right", print_object_pointer_t{p_digit_node->tree_right}))},
                                                            },
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                        }});
                                                    return result; //
                                                }(),
                                            }}}},
                            }}});

                        if(p_digit_node->tree_left != nullptr && !tagged_ptr_bit0_is_setted(p_digit_node->tree_left))
                            tree_node_recursive(p_digit_node->tree_left);
                        if(p_digit_node->tree_right != nullptr && !tagged_ptr_bit0_is_setted(p_digit_node->tree_right))
                            tree_node_recursive(p_digit_node->tree_right);
                    }

                    if constexpr(I == 0)
                    {
                        for(auto p_list_node_navigator = sequence_t::navigator_t::untagged_next_or_tagged_end(sequence.list_node_end); p_list_node_navigator != sequence.list_node_end; p_list_node_navigator = p_list_node_navigator->next)
                        {
                            auto p_list_node = static_cast<typename sequence_t::list_node_t *>(p_list_node_navigator);

                            assert(p_list_node->parent != nullptr);
                            list_node_edges.push_back(edge_statement_t{{{
                                                                           node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"parent", c},
                                                                           node_id_t{(tagged_ptr_bit0_is_setted(p_list_node->parent) ? u8"digit_node_" : u8"tree_node_") + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_list_node->parent))},
                                                                       }},
                                {{
                                    {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->parent"},
                                    {u8"style", tagged_ptr_bit0_is_setted(p_list_node->parent) ? u8"dashed" : u8"solid"},
                                    {u8"constraint", u8"false"},
                                    {u8"tailclip", u8"false"},
                                }}});

                            assert(p_list_node->prev != nullptr);
                            if(p_list_node->prev != sequence.list_node_end)
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"prev", c},
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node->prev)},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->prev"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                    }}});
                            else if constexpr(generating_list_node_front_and_back)
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"prev", c},
                                                                               node_id_t{u8"list_node_front"},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->prev"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                        {u8"style", u8"dashed"},
                                    }}});

                            assert(p_list_node->next != nullptr);
                            if(p_list_node->next != sequence.list_node_end)
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"next", c},
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node->next)},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->next"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                    }}});
                            else if constexpr(generating_list_node_front_and_back)
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"next", c},
                                                                               node_id_t{u8"list_node_back"},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->next"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                        {u8"style", u8"dashed"},
                                    }}});

                            list_nodes_same_rank.statements.push_back(node_statement_t{{u8"list_node_" + object_pointer_to_string(p_list_node)}});
                            list_nodes.push_back(node_statement_t{{u8"list_node_" + object_pointer_to_string(p_list_node)},
                                {{
                                    {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node)},
                                    {u8"label", html_label_t{fonttable_t{table_t{
                                                    .BORDER = 0,
                                                    .CELLBORDER = 1,
                                                    .CELLSPACING = 0,
                                                    .rows = [&]()
                                                    {
                                                        decltype(table_t::rows) result;
                                                        if constexpr(generating_title)
                                                            result.push_back(row_t{{
                                                                cell_t{
                                                                    .COLOR = u8"transparent",
                                                                    .COLSPAN = 3,
                                                                    .content = html_label_t{pointer_title_text_to_title_only(u8"list_node", object_pointer_to_string(p_list_node))},
                                                                },
                                                            }});
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .PORT = u8"parent",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"parent", print_object_pointer_t{p_list_node->parent}))},
                                                            },
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                        }});
                                                        if constexpr(!std::is_same_v<typename sequence_t::projected_storage_t, void>)
                                                        {
                                                            result.push_back(row_t{{
                                                                cell_t{
                                                                    .BGCOLOR = p_list_node->prev == sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                                    .PORT = u8"prev",
                                                                    .ROWSPAN = 2,
                                                                    .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"prev", print_object_pointer_t{p_list_node->prev}))},
                                                                },
                                                                cell_t{
                                                                    .content = std::get<0>(std::get<I>(to_graphs_parameters.projected_and_accumulated_storage_to_string_converter_per_sequence))(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                        .member_name =
#endif
                                                                            u8"projected_storage",
#ifndef __EMSCRIPTEN__
                                                                        .datum =
#endif
                                                                            *p_list_node->actual_projected_storage.p_projected_storage(),
#ifndef __EMSCRIPTEN__
                                                                        .converter_generated_statements_back_inserter =
#endif
                                                                            std::back_inserter(converter_generated_statements),
                                                                    }),
                                                                },
                                                                cell_t{
                                                                    .BGCOLOR = p_list_node->next == sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                                    .PORT = u8"next",
                                                                    .ROWSPAN = 2,
                                                                    .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{p_list_node->next}))},
                                                                },
                                                            }});
                                                            result.push_back(row_t{{
                                                                cell_t{
                                                                    .content = to_graphs_parameters.element_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                        .member_name =
#endif
                                                                            u8"element",
#ifndef __EMSCRIPTEN__
                                                                        .datum =
#endif
                                                                            *p_list_node->actual_projected_storage.p_element(),
#ifndef __EMSCRIPTEN__
                                                                        .converter_generated_statements_back_inserter =
#endif
                                                                            std::back_inserter(converter_generated_statements),
                                                                    }),
                                                                },
                                                            }});
                                                        }
                                                        else
                                                        {
                                                            if constexpr(print_stride1_projected_storage_td_even_if_does_not_exist)
                                                            {
                                                                result.push_back(row_t{{
                                                                    cell_t{
                                                                        .BGCOLOR = p_list_node->prev == sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                                        .PORT = u8"prev",
                                                                        .ROWSPAN = 2,
                                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"prev", print_object_pointer_t{p_list_node->prev}))},
                                                                    },
                                                                    cell_t{
                                                                        .BGCOLOR = inactive_cell_color,
                                                                        .content = html_label_t{text_t{{{u8" "}}}},
                                                                    },
                                                                    cell_t{
                                                                        .BGCOLOR = p_list_node->next == sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                                        .PORT = u8"next",
                                                                        .ROWSPAN = 2,
                                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{p_list_node->next}))},
                                                                    },
                                                                }});
                                                                result.push_back(row_t{{
                                                                    cell_t{
                                                                        .content = to_graphs_parameters.element_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                            .member_name =
#endif
                                                                                u8"element",
#ifndef __EMSCRIPTEN__
                                                                            .datum =
#endif
                                                                                *p_list_node->actual_projected_storage.p_element(),
#ifndef __EMSCRIPTEN__
                                                                            .converter_generated_statements_back_inserter =
#endif
                                                                                std::back_inserter(converter_generated_statements),
                                                                        }),
                                                                    },
                                                                }});
                                                            }
                                                            else
                                                            {
                                                                result.push_back(row_t{{
                                                                    cell_t{
                                                                        .BGCOLOR = p_list_node->prev == sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                                        .PORT = u8"prev",
                                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"prev", print_object_pointer_t{p_list_node->prev}))},
                                                                    },
                                                                    cell_t{
                                                                        .content = to_graphs_parameters.element_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                            .member_name =
#endif
                                                                                u8"element",
#ifndef __EMSCRIPTEN__
                                                                            .datum =
#endif
                                                                                *p_list_node->actual_projected_storage.p_element(),
#ifndef __EMSCRIPTEN__
                                                                            .converter_generated_statements_back_inserter =
#endif
                                                                                std::back_inserter(converter_generated_statements),
                                                                        }),
                                                                    },
                                                                    cell_t{
                                                                        .BGCOLOR = p_list_node->next == sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                                        .PORT = u8"next",
                                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{p_list_node->next}))},
                                                                    },
                                                                }});
                                                            }
                                                        }
                                                        return result; //
                                                    }(),
                                                }}}},
                                }}});
                        }
                    }
                    else
                    {
                        for(auto p_list_node_navigator = sequence_t::navigator_t::untagged_next_or_tagged_end(sequence.list_node_end); p_list_node_navigator != sequence.list_node_end; p_list_node_navigator = p_list_node_navigator->next)
                        {
                            auto p_list_node = static_cast<typename sequence_t::list_node_t *>(p_list_node_navigator);

                            assert(p_list_node->parent != nullptr);
                            list_node_edges.push_back(edge_statement_t{{{
                                                                           node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"parent", c},
                                                                           node_id_t{(tagged_ptr_bit0_is_setted(p_list_node->parent) ? u8"digit_node_" : u8"tree_node_") + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_list_node->parent))},
                                                                       }},
                                {{
                                    {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->parent"},
                                    {u8"style", tagged_ptr_bit0_is_setted(p_list_node->parent) ? u8"dashed" : u8"solid"},
                                    {u8"constraint", u8"false"},
                                    {u8"tailclip", u8"false"},
                                }}});

                            assert(p_list_node->actual_projected_storage.child != nullptr);
                            list_node_edges.push_back(edge_statement_t{{{
                                                                           node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"child", c},
                                                                           node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node->actual_projected_storage.child)},
                                                                       }},
                                {{
                                    {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->child"},
                                    {u8"constraint", u8"true"},
                                    {u8"tailclip", u8"false"},
                                }}});

                            assert(p_list_node->prev != nullptr);
                            if(p_list_node->prev != sequence.list_node_end)
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"prev", c},
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node->prev)},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->prev"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                    }}});
                            else if constexpr(generating_list_node_front_and_back)
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"prev", c},
                                                                               node_id_t{u8"list_node_front"},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->prev"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                        {u8"style", u8"dashed"},
                                    }}});

                            assert(p_list_node->next != nullptr);
                            if(p_list_node->next != sequence.list_node_end)
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"next", c},
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node->next)},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->next"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                    }}});
                            else if constexpr(generating_list_node_front_and_back)
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"next", c},
                                                                               node_id_t{u8"list_node_back"},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->next"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                        {u8"style", u8"dashed"},
                                    }}});

                            list_nodes_same_rank.statements.push_back(node_statement_t{{u8"list_node_" + object_pointer_to_string(p_list_node)}});
                            list_nodes.push_back(node_statement_t{{u8"list_node_" + object_pointer_to_string(p_list_node)},
                                {{
                                    {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node)},
                                    {u8"label", html_label_t{fonttable_t{table_t{
                                                    .BORDER = 0,
                                                    .CELLBORDER = 1,
                                                    .CELLSPACING = 0,
                                                    .rows = [&]()
                                                    {
                                                        decltype(table_t::rows) result;
                                                        if constexpr(generating_title)
                                                            result.push_back(row_t{{
                                                                cell_t{
                                                                    .COLOR = u8"transparent",
                                                                    .COLSPAN = 3,
                                                                    .content = html_label_t{pointer_title_text_to_title_only(u8"list_node", object_pointer_to_string(p_list_node))},
                                                                },
                                                            }});
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .PORT = u8"parent",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"parent", print_object_pointer_t{p_list_node->parent}))},
                                                            },
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                        }});
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .BGCOLOR = p_list_node->prev == sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                                .PORT = u8"prev",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"prev", print_object_pointer_t{p_list_node->prev}))},
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .content = std::get<0>(std::get<I>(to_graphs_parameters.projected_and_accumulated_storage_to_string_converter_per_sequence))(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"projected_storage",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        *p_list_node->actual_projected_storage.p_projected_storage(),
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
                                                                }),
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = p_list_node->next == sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                                .PORT = u8"next",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{p_list_node->next}))},
                                                            },
                                                        }});
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .PORT = u8"child",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"child", print_object_pointer_t{p_list_node->actual_projected_storage.child}))},
                                                            },
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                        }});
                                                        return result; //
                                                    }(),
                                                }}}},
                                }}});
                        }

                        for(auto p_list_node_navigator = sequence_t::navigator_t::untagged_next_or_tagged_end(stride1_sequence.list_node_end); p_list_node_navigator != stride1_sequence.list_node_end; p_list_node_navigator = p_list_node_navigator->next)
                        {
                            auto p_list_node = static_cast<typename stride1_sequence_t::list_node_t *>(p_list_node_navigator);

                            assert(std::get<I - 1>(p_list_node->actual_projected_storage.parents) != nullptr);
                            list_node_edges.push_back(edge_statement_t{{{
                                                                           node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"parent", c},
                                                                           node_id_t{u8"list_node_" + object_pointer_to_string(std::get<I - 1>(p_list_node->actual_projected_storage.parents))},
                                                                       }},
                                {{
                                    {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->parent"},
                                    {u8"constraint", u8"false"},
                                    {u8"tailclip", u8"false"},
                                }}});

                            assert(p_list_node->prev != nullptr);
                            if(p_list_node->prev != stride1_sequence.list_node_end)
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"prev", c},
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node->prev)},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->prev"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                    }}});

                            assert(p_list_node->next != nullptr);
                            if(p_list_node->next != stride1_sequence.list_node_end)
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"next", c},
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node->next)},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->next"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                    }}});

                            stride1_list_nodes_same_rank.statements.push_back(node_statement_t{{u8"list_node_" + object_pointer_to_string(p_list_node)}});

                            list_nodes.push_back(node_statement_t{{u8"list_node_" + object_pointer_to_string(p_list_node)},
                                {{
                                    {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node)},
                                    {u8"label", html_label_t{fonttable_t{table_t{
                                                    .BORDER = 0,
                                                    .CELLBORDER = 1,
                                                    .CELLSPACING = 0,
                                                    .rows = [&]()
                                                    {
                                                        decltype(table_t::rows) result;
                                                        if constexpr(generating_title)
                                                            result.push_back(row_t{{
                                                                cell_t{
                                                                    .COLOR = u8"transparent",
                                                                    .COLSPAN = 3,
                                                                    .content = html_label_t{pointer_title_text_to_title_only(u8"list_node", object_pointer_to_string(p_list_node))},
                                                                },
                                                            }});
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .PORT = u8"parent",
                                                                .content = html_label_t{pointer_member_text_to_space(not_member_to_text(u8"parent", print_object_pointer_t{std::get<I - 1>(p_list_node->actual_projected_storage.parents)}))},
                                                            },
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                            },
                                                        }});
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .BGCOLOR = p_list_node->prev == stride1_sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                                .PORT = u8"prev",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"prev", print_object_pointer_t{p_list_node->prev}))},
                                                            },
                                                            cell_t{
                                                                .content = to_graphs_parameters.element_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"element",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        *p_list_node->actual_projected_storage.p_element(),
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
                                                                }),
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = p_list_node->next == stride1_sequence.list_node_end ? inactive_cell_color : active_cell_color,
                                                                .PORT = u8"next",
                                                                .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{p_list_node->next}))},
                                                            },
                                                        }});
                                                        return result; //
                                                    }(),
                                                }}}},
                                }}});
                        }
                    }
                    std::ranges::for_each(to_graphs_parameters.iterators_element, [&, index = 0](auto iterator_element) mutable
                        {
                            if([&]()
                                {if constexpr(I == 0)return iterator_element.current_list_node != sequence.list_node_end; else return iterator_element.current_list_node !=stride1_sequence.list_node_end; }())
                            {
                                iterator_element_nodes.push_back(node_statement_t{{u8"it[" + index_to_string(index) + u8"]"},
                                    {{
                                        {u8"id", u8"it[" + index_to_string(index) + u8"]"},
                                        {u8"label", u8"it[" + index_to_string(index) + u8"]"},
                                    }}});
                                iterator_element_edges.push_back(edge_statement_t{{{
                                                                                      node_id_t{u8"list_node_" + object_pointer_to_string(iterator_element.current_list_node)},
                                                                                      node_id_t{u8"it[" + index_to_string(index) + u8"]", std::nullopt, c},
                                                                                  }},
                                    {{
                                        {u8"id", u8"it[" + index_to_string(index) + u8"]" + u8"->list_node"},
                                        {u8"dir", u8"back"},
                                    }}});
                            }
                            ++index; //
                        });
                    if constexpr(!std::is_same_v<decltype(to_graphs_parameters.iterators_projected_storage_per_sequence), std::nullopt_t>)
                    {
                        std::ranges::for_each(std::get<I>(to_graphs_parameters.iterators_projected_storage_per_sequence), [&, index = 0](auto iterator_projected_storage) mutable
                            {
                                if(iterator_projected_storage.current_list_node != sequence.list_node_end)
                                {
                                    iterator_projected_storage_nodes.push_back(node_statement_t{{u8"itp[" + index_to_string(index) + u8"]"},
                                        {{
                                            {u8"id", u8"itp[" + index_to_string(index) + u8"]"},
                                            {u8"label", u8"itp[" + index_to_string(index) + u8"]"},
                                        }}});
                                    iterator_projected_storage_edges.push_back(edge_statement_t{{{
                                                                                                    node_id_t{u8"list_node_" + object_pointer_to_string(iterator_projected_storage.current_list_node)},
                                                                                                    node_id_t{u8"itp[" + index_to_string(index) + u8"]", std::nullopt, c},
                                                                                                }},
                                        {{
                                            {u8"id", u8"itp[" + index_to_string(index) + u8"]" + u8"->list_node"},
                                            {u8"dir", u8"back"},
                                        }}});
                                }
                                ++index; //
                            });
                    }

                    graph_t g{
                        .is_strict = false,
                        .is_directed = true,
                        .name = std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "augmented_deque_sequence_" << I).str().data())),
                        .statements = {
                            attr_t{u8"label", u8""},
                            attr_t{u8"id", u8"sequence"},

                            attr_t{u8"compound", u8"true"},
                            attr_t{u8"rankdir", u8"TB"},
                            attr_t{u8"outputorder", u8"nodesfirst"},
                            attr_t{u8"fontname", u8"Consolas"},
                            attr_t{u8"bgcolor", u8"transparent"},
                            attr_t{u8"labeljust", u8"c"},
                            attr_t{u8"labelloc", u8"t"},
                            attr_t{u8"forcelabels", u8"true"},
                            attr_t{u8"color", std::get<I>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                            attr_statement_t{graph, {{
                                                        {u8"compound", u8"true"},
                                                        {u8"rankdir", u8"TB"},
                                                        {u8"outputorder", u8"nodesfirst"},
                                                        {u8"fontname", u8"Consolas"},
                                                        {u8"bgcolor", u8"transparent"},
                                                        {u8"labeljust", u8"c"},
                                                        {u8"labelloc", u8"t"},
                                                        {u8"color", std::get<I>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                    }}},
                            attr_statement_t{node, {{
                                                       {u8"shape", u8"plain"},
                                                       {u8"fontname", u8"Consolas"},
                                                       {u8"color", std::get<I>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                   }}},
                        },
                    };
                    std::ranges::copy(digit_nodes, std::back_inserter(g.statements));
                    std::ranges::copy(tree_nodes, std::back_inserter(g.statements));
                    std::ranges::copy(list_nodes, std::back_inserter(g.statements));
                    std::ranges::copy(iterator_element_nodes, std::back_inserter(g.statements));
                    std::ranges::copy(iterator_projected_storage_nodes, std::back_inserter(g.statements));
                    std::ranges::copy(digit_node_edges, std::back_inserter(g.statements));
                    std::ranges::copy(tree_node_edges, std::back_inserter(g.statements));
                    std::ranges::copy(list_node_edges, std::back_inserter(g.statements));
                    std::ranges::copy(iterator_element_edges, std::back_inserter(g.statements));
                    std::ranges::copy(iterator_projected_storage_edges, std::back_inserter(g.statements));

                    g.statements.push_back(digit_nodes_same_rank);
                    g.statements.push_back(list_nodes_same_rank);
                    g.statements.push_back(stride1_list_nodes_same_rank);

                    //sequence use cluster
                    g.statements.push_back(sequence_members_render_from_left_to_right_node);
                    g.statements.push_back(sequence_members);
                    g.statements.push_back(sequence_members_digit_end_accumulated_storage);
                    std::ranges::copy(sequence_members_render_from_left_to_right_edges, std::back_inserter(g.statements));
                    std::ranges::copy(sequence_members_edges, std::back_inserter(g.statements));

                    std::ranges::copy(converter_generated_statements, std::back_inserter(g.statements));

                    return g; //
                }()...};
        }
        (std::make_index_sequence<augmented_deque_t<element_t, allocator_element_t, config_t>::sequences_count>());
    }
} // namespace augmented_containers

#endif // AUGMENTED_DEQUE_VISUALIZATION_HPP
