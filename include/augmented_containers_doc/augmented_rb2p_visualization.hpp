#ifndef AUGMENTED_RB2P_VISUALIZATION_HPP
#define AUGMENTED_RB2P_VISUALIZATION_HPP

#include <augmented_containers/augmented_rb2p.hpp>
#include "ext_infrastructure/ext_graphviz.hpp"
#include <sstream>
#include <iomanip>
#include <functional>
#include <optional>
#include <map>

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
            dot::text_t pointer_member_text_to_space(dot::text_t text, dot::textitem_t text_tags)
            {
                using namespace dot;
                if(true)
                    return text_t{{text_tags}};
                else
                {
                    text.items.insert(text.items.begin(), {
                                                              text_tags,
                                                              {br_t{.ALIGN = LEFT}},
                                                          });
                    text.items.push_back({br_t{.ALIGN = LEFT}});
                    return text;
                }
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

            namespace augmented_sequence_rb2p
            {
                enum class accumulated_storage_node_type_e { uninitialized,
                    tree_node,
                    read_range };

                template<typename datum_t, typename converter_generated_statements_back_inserter_t>
                struct to_string_converter_parameters_t
                {
                    std::size_t container_index;
                    std::u8string const &member_name;
                    datum_t const &datum;
                    converter_generated_statements_back_inserter_t converter_generated_statements_back_inserter;
                    accumulated_storage_node_type_e accumulated_storage_node_type;
                };
#if __cpp_deduction_guides >= 201907L
#else
                template<typename datum_t, typename converter_generated_statements_back_inserter_t>
                to_string_converter_parameters_t(std::size_t, std::u8string const &, datum_t const &, converter_generated_statements_back_inserter_t, accumulated_storage_node_type_e) -> to_string_converter_parameters_t<datum_t, converter_generated_statements_back_inserter_t>;
                template<typename datum_t, typename converter_generated_statements_back_inserter_t>
                to_string_converter_parameters_t(std::size_t, std::u8string const &, datum_t const &, converter_generated_statements_back_inserter_t) -> to_string_converter_parameters_t<datum_t, converter_generated_statements_back_inserter_t>;
#endif

                template<typename element_to_string_converter_t, typename accumulated_storage_to_string_converter_t, typename iterators_t, typename iterators_container_index_t, typename read_range_t = std::nullopt_t, typename iterators_output_t = std::nullopt_t>
                struct to_graphs_parameters_t
                {
                    element_to_string_converter_t element_to_string_converter;
                    accumulated_storage_to_string_converter_t accumulated_storage_to_string_converter;
                    iterators_t iterators;
                    iterators_container_index_t iterators_container_index;
                    read_range_t read_range = std::nullopt;
                    iterators_output_t iterators_output = std::nullopt;
                };
#if __cpp_deduction_guides >= 201907L
#else
                template<typename... T>
                to_graphs_parameters_t(T...) -> to_graphs_parameters_t<T...>;
#endif
            } // namespace augmented_sequence_rb2p
        } // namespace visualization
    } // namespace detail
    template<typename element_t, typename allocator_element_t, typename accumulator_t, typename size_management_t, typename... to_graphs_parameters_t_parameters_t>
    std::vector<dot::graph_t> to_graphs(std::vector<augmented_sequence_t<element_t, allocator_element_t, accumulator_t, std::integral_constant<augmented_sequence_physical_representation_e, augmented_sequence_physical_representation_e::rb2p>, size_management_t>> const &augmented_sequence_rb2p_s, detail::visualization::augmented_sequence_rb2p::to_graphs_parameters_t<to_graphs_parameters_t_parameters_t...> to_graphs_parameters)
    {
        using namespace dot;
        using namespace detail::language;
        using namespace detail::visualization;
        using namespace detail::visualization::augmented_sequence_rb2p;

        using container_t = std::remove_cvref_t<decltype(augmented_sequence_rb2p_s)>::value_type;

        constexpr bool generating_title = false;

        std::map<detail::augmented_sequence_rb2p::rb2p_node_role_e, std::u8string> rb2p_node_role_symbols{
            {detail::augmented_sequence_rb2p::rb2p_node_role_e::end, u8"△"},
            {detail::augmented_sequence_rb2p::rb2p_node_role_e::root, u8"▽"},
            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_not_a_leftmost_descendent, u8"◤"},
            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_non_root, u8"◢"},
            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root, u8"◁"},
            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_not_a_rightmost_descendent, u8"◥"},
            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_non_root, u8"◣"},
            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_root, u8"▷"},
        };
        //        std::map<rb2p_node_role_e, std::u8string> rb2p_node_role_symbols{
        //            {detail::augmented_sequence_rb2p::rb2p_node_role_e::end, u8"▲"},
        //            {detail::augmented_sequence_rb2p::rb2p_node_role_e::root, u8"▼"},
        //            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_not_a_leftmost_descendent, u8"◸"},
        //            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_non_root, u8"◿"},
        //            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root, u8"◀"},
        //            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_not_a_rightmost_descendent, u8"◹"},
        //            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_non_root, u8"◺"},
        //            {detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_root, u8"▶"},
        //        };

        std::vector<std::variant<node_statement_t, edge_statement_t, attr_statement_t, attr_t, subgraph_t>> converter_generated_statements;

        graph_t g{
            .is_strict = false,
            .is_directed = true,
            .name = std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "augmented_sequence_rb2p").str().data())),
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
                attr_t{u8"color", u8"#000000"},
                //                attr_t{u8"splines", u8"line"},
                attr_statement_t{graph, {{
                                            {u8"compound", u8"true"},
                                            {u8"rankdir", u8"TB"},
                                            {u8"outputorder", u8"nodesfirst"},
                                            {u8"fontname", u8"Consolas"},
                                            {u8"bgcolor", u8"transparent"},
                                            {u8"labeljust", u8"c"},
                                            {u8"labelloc", u8"t"},
                                            {u8"color", u8"#000000"},
                                        }}},
                attr_statement_t{node, {{
                                           {u8"shape", u8"plain"},
                                           {u8"fontname", u8"Consolas"},
                                           {u8"color", u8"#000000"},
                                       }}},
            },
        };
        subgraph_t read_range_accumulated_storages{
            .name = u8"read_range_accumulated_storages",
            .statements = {
                attr_t{u8"label", u8""},
                attr_t{u8"id", u8"read_range_accumulated_storages"},

                attr_t{u8"cluster", u8"false"},
                attr_t{u8"rank", u8"sink"},
            },
        };

        for(container_t const &augmented_sequence_rb2p : augmented_sequence_rb2p_s)
        {
            typename container_t::node_end_t *p_node_end = augmented_sequence_rb2p.node_end;
            std::size_t container_index = &augmented_sequence_rb2p - &augmented_sequence_rb2p_s[0];

            std::vector<edge_statement_t> tree_node_end_edges;

            if(tagged_ptr_bit0_unsetted(p_node_end->parent_all()) != p_node_end)
            {
                assert(p_node_end->child_right_all() != nullptr);
                assert(tagged_ptr_bit0_is_setted(p_node_end->child_right_all()));
                //            tree_node_end_edges.push_back(edge_statement_t{{{
                //                                                               node_id_t{u8"tree_node_" + object_pointer_to_string(p_node_end)},
                //                                                               node_id_t{u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted(p_node_end->child_right_all()))},
                //                                                           }},
                //                {{
                //                    {u8"id", u8"tree_node_" + object_pointer_to_string(p_node_end) + u8"->child_right"},
                //                    {u8"style", u8"solid"},
                //                    {u8"constraint", u8"false"},
                //                    {u8"arrowhead", u8"none"},
                //                    {u8"color", u8"#0000FF"},
                //                }}});

                assert(p_node_end->parent_all() != nullptr);
                assert(tagged_ptr_bit0_is_setted(p_node_end->parent_all()));
                tree_node_end_edges.push_back(edge_statement_t{{{
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(p_node_end)},
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted(p_node_end->parent_all()))},
                                                               }},
                    {{
                        {u8"id", u8"tree_node_" + object_pointer_to_string(p_node_end) + u8"->parent"},
                        {u8"style", u8"solid"},
                        {u8"constraint", u8"true"},
                        {u8"arrowhead", u8"none"},
                        {u8"color", u8"#0000FF"},
                    }}});

                assert(p_node_end->child_left_all() != nullptr);
                assert(tagged_ptr_bit0_is_setted(p_node_end->child_left_all()));
                //            tree_node_end_edges.push_back(edge_statement_t{{{
                //                                                               node_id_t{u8"tree_node_" + object_pointer_to_string(p_node_end)},
                //                                                               node_id_t{u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted(p_node_end->child_left_all()))},
                //                                                           }},
                //                {{
                //                    {u8"id", u8"tree_node_" + object_pointer_to_string(p_node_end) + u8"->child_left"},
                //                    {u8"style", u8"solid"},
                //                    {u8"constraint", u8"false"},
                //                    {u8"arrowhead", u8"none"},
                //                    {u8"color", u8"#0000FF"},
                //                }}});
            }

            node_statement_t tree_node_end{{u8"tree_node_" + object_pointer_to_string(p_node_end)},
                {{
                    {u8"id", u8"tree_node_" + object_pointer_to_string(p_node_end)},
                    {u8"label", html_label_t{fonttable_t{table_t{
                                    .BORDER = 0,
                                    .CELLBORDER = 1,
                                    .CELLSPACING = 0,
                                    .COLOR = u8"#888888",
                                    .rows = [&]()
                                    {
                                        decltype(table_t::rows) result;
                                        if constexpr(generating_title)
                                            result.push_back(row_t{{
                                                cell_t{
                                                    .COLOR = u8"transparent",
                                                    .content = html_label_t{pointer_title_text_to_title_only(u8"tree_node", object_pointer_to_string(p_node_end))},
                                                },
                                            }});
                                        if constexpr(static_cast<augmented_sequence_size_management_e>(typename container_t::augmented_sequence_size_management_t{}) == augmented_sequence_size_management_e::at_node_end)
                                            result.push_back(
                                                row_t{{
                                                    cell_t{
                                                        .BGCOLOR = active_cell_color,
                                                        .PORT = u8"node_count",
                                                        .content = html_label_t{text_t{{{u8"n:"}, {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << p_node_end->node_count).str().data()))}}}},
                                                    },
                                                }});
                                        result.push_back(
                                            row_t{{
                                                cell_t{
                                                    .BGCOLOR = active_cell_color,
                                                    .BORDER = 2,
                                                    .PORT = u8"my_list_begin",
                                                    .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"my_list_begin", print_object_pointer_t{static_cast<typename container_t::node_t *>(static_cast<typename container_t::navigator_t *>(p_node_end->my_list_begin()))}), textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF", .FACE = u8"Cambria Math"}, text_t{{{rb2p_node_role_symbols.at(p_node_end->role())}}})})},
                                                },
                                            }});
                                        return result; //
                                    }(),
                                }}}},
                }}};

            std::vector<subgraph_t> tree_node_clusters;
            std::vector<edge_statement_t> tree_node_edges;

            assert(p_node_end->my_list_begin() != nullptr);
            //            tree_node_edges.push_back(edge_statement_t{{{
            //                                                           node_id_t{u8"tree_node_" + object_pointer_to_string(p_node_end), u8"my_list_begin", c},
            //                                                           node_id_t{u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_node_end->my_list_begin())), [&]() -> std::optional<id_t>
            //                                                               {
            //                                                                   typename container_t::navigator_t *loop_end_next = container_t::navigator_t::get_loop_end_next(p_node_end);
            //                                                                   if(loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::end || loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root)
            //                                                                       return u8"my_list_begin";
            //                                                                   else if(loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::root)
            //                                                                       return u8"next";
            //                                                                   else
            //                                                                       std::unreachable();
            //                                                               }(),
            //                                                               c},
            //                                                       }},
            //                {{
            //                    {u8"id", /*u8"tree_node_" + object_pointer_to_string(p_node_end) + u8"->my_list_begin"*/ [&]() -> std::u8string
            //                            {
            //                                typename container_t::navigator_t *loop_end_next = container_t::navigator_t::get_loop_end_next(p_node_end);
            //                                if(loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::end)
            //                                    return u8"inner";
            //                                if(loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root || loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::root)
            //                                    return u8"outer";
            //                                else
            //                                    std::unreachable();
            //                            }() +
            //                            u8"->tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_node_end->my_list_begin()))},
            //                    {u8"style", tagged_ptr_bit0_is_setted(p_node_end->my_list_begin()) ? u8"dashed" : u8"solid"},
            //                    {u8"constraint", u8"false"},
            //                    {u8"tailclip", u8"false"},
            //                    {u8"headclip", u8"false"},
            //                }}});

            std::function<void(typename container_t::node_t *, std::optional<std::reference_wrapper<std::vector<node_statement_t>>>)> tree_node_recursive = [&](typename container_t::node_t *p_tree_node, std::optional<std::reference_wrapper<std::vector<node_statement_t>>> tree_nodes_from_black_parent)
            {
                //                qDebug() << *p_tree_node;
                assert(!(p_tree_node->child_left_all() != nullptr && tagged_ptr_bit0_is_setted(p_tree_node->child_left_all())) || static_cast<typename container_t::navigator_t *>(p_tree_node->child_left_all()) == tagged_ptr_bit0_setted(augmented_sequence_rb2p.node_end));
                if(p_tree_node->child_left() != nullptr)
                {
                    tree_node_edges.push_back(edge_statement_t{{{
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node)},
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(static_cast<typename container_t::navigator_t *>(p_tree_node->child_left()))},
                                                               }},
                        {{
                            {u8"id", u8"parent->" + (u8"tree_node_" + object_pointer_to_string(static_cast<typename container_t::navigator_t *>(p_tree_node->child_left())))},
                            {u8"style", u8"solid"},
                            //                        {u8"constraint", u8"true"},
                            {u8"constraint", !p_tree_node->color() && p_tree_node->child_left()->color() ? u8"false" : u8"true"},
                            {u8"arrowhead", u8"none"},
                            {u8"color", u8"#0000FF"},
                        }}});
                }

                assert(p_tree_node->parent_all() != nullptr);
                assert(!tagged_ptr_bit0_is_setted(p_tree_node->parent_all()) || p_tree_node->parent_all() == tagged_ptr_bit0_setted(augmented_sequence_rb2p.node_end));

                assert(!(p_tree_node->child_right_all() != nullptr && tagged_ptr_bit0_is_setted(p_tree_node->child_right_all())) || static_cast<typename container_t::navigator_t *>(p_tree_node->child_right_all()) == tagged_ptr_bit0_setted(augmented_sequence_rb2p.node_end));
                if(p_tree_node->child_right() != nullptr)
                {
                    tree_node_edges.push_back(edge_statement_t{{{
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node)},
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(static_cast<typename container_t::navigator_t *>(p_tree_node->child_right()))},
                                                               }},
                        {{
                            {u8"id", u8"parent->" + (u8"tree_node_" + object_pointer_to_string(static_cast<typename container_t::navigator_t *>(p_tree_node->child_right())))},
                            {u8"style", u8"solid"},
                            //                        {u8"constraint", u8"true"},
                            {u8"constraint", !p_tree_node->color() && p_tree_node->child_right()->color() ? u8"false" : u8"true"},
                            {u8"arrowhead", u8"none"},
                            {u8"color", u8"#0000FF"},
                        }}});
                }

                assert(p_tree_node->my_list_begin() != nullptr);
                if(p_tree_node->role() != detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root && p_tree_node->role() != detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_root)
                    tree_node_edges.push_back(edge_statement_t{{{
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"my_list_begin", c},
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->my_list_begin())), [&]() -> std::optional<id_t>
                                                                       {
                                                                           switch(p_tree_node->role())
                                                                           {
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::root:
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_not_a_leftmost_descendent:
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_not_a_rightmost_descendent:
                                                                           {
                                                                               auto [index, loop_next] = container_t::navigator_t::get_loop_next(0, p_tree_node);
                                                                               if(index == 1 || index == 4)
                                                                                   return u8"next";
                                                                               else if(index == 0)
                                                                                   return u8"my_list_begin";
                                                                               else
                                                                                   std::unreachable();
                                                                           } break;
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_non_root:
                                                                           {
                                                                               auto [index, loop_next] = container_t::navigator_t::get_loop_next(2, p_tree_node);
                                                                               if(index == 3)
                                                                                   return u8"my_list_begin";
                                                                               else if(index == 4)
                                                                                   return u8"next";
                                                                               else
                                                                                   std::unreachable();
                                                                           } break;
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_non_root:
                                                                           {
                                                                               auto [index, loop_next] = container_t::navigator_t::get_loop_next(3, p_tree_node);
                                                                               if(index == 4)
                                                                                   return u8"next";
                                                                               else
                                                                                   std::unreachable();
                                                                           } break;
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root:
                                                                           {
                                                                               typename container_t::navigator_t *loop_end_next = container_t::navigator_t::get_loop_end_next(p_tree_node);
                                                                               if(loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::root)
                                                                                   return u8"next";
                                                                               else
                                                                                   std::unreachable();
                                                                           } break;
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_root:
                                                                           {
                                                                               typename container_t::navigator_t *loop_end_next = container_t::navigator_t::get_loop_end_next(p_tree_node);
                                                                               if(loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::end)
                                                                                   return u8"my_list_begin";
                                                                               else
                                                                                   std::unreachable();
                                                                           } break;
                                                                           default:
                                                                               std::unreachable();
                                                                               break;
                                                                           }
                                                                       }(),
                                                                       c},
                                                               }},
                        {{
                            {u8"id", /*u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"->my_list_begin"*/ [&]() -> std::u8string
                                    {
                                        switch(p_tree_node->role())
                                        {
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::root:
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_not_a_leftmost_descendent:
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_not_a_rightmost_descendent:
                                        {
                                            auto [index, loop_next] = container_t::navigator_t::get_loop_next(0, p_tree_node);
                                            if(index == 1 || index == 4)
                                            {
                                                switch(loop_next->role())
                                                {
                                                case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_not_a_rightmost_descendent:
                                                    return u8"outer";
                                                    break;
                                                case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_non_root:
                                                case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root:
                                                case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_non_root:
                                                case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_root:
                                                    return u8"inner";
                                                default:
                                                    std::unreachable();
                                                    break;
                                                }
                                            }
                                            else if(index == 0)
                                                return u8"inner";
                                            else
                                                std::unreachable();
                                        } break;
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_non_root:
                                        {
                                            auto [index, loop_next] = container_t::navigator_t::get_loop_next(2, p_tree_node);
                                            if(index == 3)
                                                return u8"outer";
                                            else if(index == 4)
                                            {
                                                switch(loop_next->role())
                                                {
                                                case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_not_a_leftmost_descendent:
                                                    return u8"outer";
                                                    break;
                                                case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_non_root:
                                                case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root:
                                                    return u8"inner";
                                                default:
                                                    std::unreachable();
                                                    break;
                                                }
                                            }
                                            else
                                                std::unreachable();
                                        } break;
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_non_root:
                                            return u8"outer";
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root:
                                            return u8"outer";
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_root:
                                            return u8"inner";
                                            break;
                                        default:
                                            std::unreachable();
                                            break;
                                        }
                                    }() +
                                    u8"->tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->my_list_begin()))},
                            {u8"style", tagged_ptr_bit0_is_setted(p_tree_node->my_list_begin()) ? u8"dashed" : u8"solid"},
                            {u8"constraint", u8"false"},
                            {u8"tailclip", u8"false"},
                            {u8"headclip", u8"false"},
                        }}});

                assert(p_tree_node->next() != nullptr);
                if(p_tree_node->role() != detail::augmented_sequence_rb2p::rb2p_node_role_e::root)
                    tree_node_edges.push_back(edge_statement_t{{{
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"next", c},
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->next())), [&]() -> std::optional<id_t>
                                                                       {
                                                                           switch(p_tree_node->role())
                                                                           {
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::root:
                                                                           {
                                                                               typename container_t::navigator_t *loop_end_next = container_t::navigator_t::get_loop_end_next(p_tree_node);
                                                                               if(loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_root || loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::end)
                                                                                   return u8"my_list_begin";
                                                                               else
                                                                                   std::unreachable();
                                                                           } break;
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_not_a_leftmost_descendent:
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_non_root:
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root:
                                                                           {
                                                                               auto [index, loop_next] = container_t::navigator_t::get_loop_next(4, p_tree_node);
                                                                               if(index == 0)
                                                                                   return u8"my_list_begin";
                                                                               else
                                                                                   std::unreachable();
                                                                           } break;
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_not_a_rightmost_descendent:
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_non_root:
                                                                           case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_root:
                                                                           {
                                                                               auto [index, loop_next] = container_t::navigator_t::get_loop_next(1, p_tree_node);
                                                                               if(index == 2 || index == 3)
                                                                                   return u8"my_list_begin";
                                                                               else if(index == 4)
                                                                                   return u8"next";
                                                                               else if(index == 0)
                                                                                   return u8"my_list_begin";
                                                                               else
                                                                                   std::unreachable();
                                                                           } break;
                                                                           default:
                                                                               std::unreachable();
                                                                               break;
                                                                           }
                                                                       }(),
                                                                       c},
                                                               }},
                        {{
                            {u8"id", /*u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"->next"*/ [&]() -> std::u8string
                                    {
                                        switch(p_tree_node->role())
                                        {
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::root:
                                        {
                                            typename container_t::navigator_t *loop_end_next = container_t::navigator_t::get_loop_end_next(p_tree_node);
                                            if(loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_root)
                                                return u8"outer";
                                            else if(loop_end_next->role() == detail::augmented_sequence_rb2p::rb2p_node_role_e::end)
                                                return u8"inner";
                                            else
                                                std::unreachable();
                                        } break;
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_not_a_leftmost_descendent:
                                            return u8"inner";
                                            break;
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_not_a_rightmost_descendent:
                                        {
                                            auto [index, loop_next] = container_t::navigator_t::get_loop_next(1, p_tree_node);
                                            if(index == 2 || index == 3 || index == 4)
                                                return u8"outer";
                                            else if(index == 0)
                                                return u8"inner";
                                            else
                                                std::unreachable();
                                        } break;
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_non_root:
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_non_root:
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root:
                                        case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_root:
                                            return u8"inner";
                                            break;
                                        default:
                                            std::unreachable();
                                            break;
                                        }
                                    }() +
                                    u8"->tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->next()))},
                            {u8"style", tagged_ptr_bit0_is_setted(p_tree_node->next()) ? u8"dashed" : u8"solid"},
                            {u8"constraint", u8"false"},
                            {u8"tailclip", u8"false"},
                            {u8"headclip", u8"false"},
                        }}});

                std::vector<node_statement_t> tree_nodes_black_this;
                std::vector<node_statement_t> &tree_nodes = !p_tree_node->color() ? tree_nodes_black_this : tree_nodes_from_black_parent.value().get();

                if(p_tree_node->child_left() != nullptr && !tagged_ptr_bit0_is_setted(p_tree_node->child_left()))
                    tree_node_recursive(static_cast<typename container_t::node_t *>(static_cast<typename container_t::navigator_t *>(p_tree_node->child_left())), !p_tree_node->color() ? std::make_optional(std::ref(tree_nodes_black_this)) : std::nullopt);

                tree_nodes.push_back(node_statement_t{{u8"tree_node_" + object_pointer_to_string(p_tree_node)},
                    {{
                        {u8"id", u8"tree_node_" + object_pointer_to_string(p_tree_node)},
                        {u8"label", html_label_t{fonttable_t{table_t{
                                        .BORDER = 0,
                                        .CELLBORDER = 1,
                                        .CELLSPACING = 0,
                                        .COLOR = !p_tree_node->color() ? u8"#000000" : u8"#FF0000",
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
                                            switch(p_tree_node->role())
                                            {
                                            case detail::augmented_sequence_rb2p::rb2p_node_role_e::root:
                                                result.push_back(
                                                    row_t{{
                                                        cell_t{
                                                            .COLOR = u8"transparent",
                                                        },
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 2,
                                                            .PORT = u8"next",
                                                            .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->next())}))},
                                                        },
                                                        cell_t{
                                                            .COLOR = u8"transparent",
                                                        },
                                                    }});
                                                if constexpr(static_cast<augmented_sequence_size_management_e>(typename container_t::augmented_sequence_size_management_t{}) == augmented_sequence_size_management_e::at_each_node_except_node_end)
                                                    result.push_back(
                                                        row_t{{
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 4,
                                                                .PORT = u8"node_count",
                                                                .content = html_label_t{text_t{{{u8"n:"}, {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << p_tree_node->node_count).str().data()))}}}},
                                                            },
                                                        }});
                                                if constexpr(!std::is_same_v<typename container_t::accumulated_storage_t, void>)
                                                    result.push_back(row_t{{
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 4,
                                                            .content = to_graphs_parameters.accumulated_storage_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .container_index =
#endif
                                                                    container_index,
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
                                                        .COLSPAN = 4,
                                                        .content = to_graphs_parameters.element_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                            .container_index =
#endif
                                                                container_index,
#ifndef __EMSCRIPTEN__
                                                            .member_name =
#endif
                                                                u8"element",
#ifndef __EMSCRIPTEN__
                                                            .datum =
#endif
                                                                *p_tree_node->p_element(),
#ifndef __EMSCRIPTEN__
                                                            .converter_generated_statements_back_inserter =
#endif
                                                                std::back_inserter(converter_generated_statements),
                                                        }),
                                                    },
                                                }});
                                                result.push_back(row_t{{
                                                    cell_t{
                                                        .COLOR = u8"transparent",
                                                        .COLSPAN = 2,
                                                    },
                                                    cell_t{
                                                        .BGCOLOR = active_cell_color,
                                                        .BORDER = 2,
                                                        .COLSPAN = 2,
                                                        .PORT = u8"my_list_begin",
                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"my_list_begin", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->my_list_begin())}), textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF", .FACE = u8"Cambria Math"}, text_t{{{rb2p_node_role_symbols.at(p_tree_node->role())}}})})},
                                                    },
                                                }});
                                                break;
                                            case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_not_a_leftmost_descendent:
                                                result.push_back(
                                                    row_t{{
                                                        cell_t{
                                                            .COLOR = u8"transparent",
                                                            .COLSPAN = 2,
                                                        },
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 2,
                                                            .PORT = u8"next",
                                                            .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->next())}))},
                                                        },
                                                    }});
                                                if constexpr(static_cast<augmented_sequence_size_management_e>(typename container_t::augmented_sequence_size_management_t{}) == augmented_sequence_size_management_e::at_each_node_except_node_end)
                                                    result.push_back(
                                                        row_t{{
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 4,
                                                                .PORT = u8"node_count",
                                                                .content = html_label_t{text_t{{{u8"n:"}, {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << p_tree_node->node_count).str().data()))}}}},
                                                            },
                                                        }});
                                                if constexpr(!std::is_same_v<typename container_t::accumulated_storage_t, void>)
                                                    result.push_back(row_t{{
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 4,
                                                            .content = to_graphs_parameters.accumulated_storage_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .container_index =
#endif
                                                                    container_index,
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
                                                        .COLSPAN = 4,
                                                        .content = to_graphs_parameters.element_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                            .container_index =
#endif
                                                                container_index,
#ifndef __EMSCRIPTEN__
                                                            .member_name =
#endif
                                                                u8"element",
#ifndef __EMSCRIPTEN__
                                                            .datum =
#endif
                                                                *p_tree_node->p_element(),
#ifndef __EMSCRIPTEN__
                                                            .converter_generated_statements_back_inserter =
#endif
                                                                std::back_inserter(converter_generated_statements),
                                                        }),
                                                    },
                                                }});
                                                result.push_back(row_t{{
                                                    cell_t{
                                                        .COLOR = u8"transparent",
                                                        .COLSPAN = 2,
                                                    },
                                                    cell_t{
                                                        .BGCOLOR = active_cell_color,
                                                        .BORDER = 2,
                                                        .COLSPAN = 2,
                                                        .PORT = u8"my_list_begin",
                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"my_list_begin", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->my_list_begin())}), textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF", .FACE = u8"Cambria Math"}, text_t{{{rb2p_node_role_symbols.at(p_tree_node->role())}}})})},
                                                    },
                                                }});
                                                break;
                                            case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_non_root:
                                                result.push_back(
                                                    row_t{{
                                                        cell_t{
                                                            .COLOR = u8"transparent",
                                                            .COLSPAN = 4,
                                                        },
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 2,
                                                            .PORT = u8"next",
                                                            .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->next())}))},
                                                        },
                                                    }});
                                                if constexpr(static_cast<augmented_sequence_size_management_e>(typename container_t::augmented_sequence_size_management_t{}) == augmented_sequence_size_management_e::at_each_node_except_node_end)
                                                    result.push_back(
                                                        row_t{{
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                                .COLSPAN = 2,
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 4,
                                                                .PORT = u8"node_count",
                                                                .content = html_label_t{text_t{{{u8"n:"}, {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << p_tree_node->node_count).str().data()))}}}},
                                                            },
                                                        }});
                                                if constexpr(!std::is_same_v<typename container_t::accumulated_storage_t, void>)
                                                    result.push_back(row_t{{
                                                        cell_t{
                                                            .COLOR = u8"transparent",
                                                            .COLSPAN = 2,
                                                        },
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 4,
                                                            .content = to_graphs_parameters.accumulated_storage_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .container_index =
#endif
                                                                    container_index,
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
                                                        .BORDER = 2,
                                                        .COLSPAN = 2,
                                                        .PORT = u8"my_list_begin",
                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"my_list_begin", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->my_list_begin())}), textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF", .FACE = u8"Cambria Math"}, text_t{{{rb2p_node_role_symbols.at(p_tree_node->role())}}})})},
                                                    },
                                                    cell_t{
                                                        .BGCOLOR = active_cell_color,
                                                        .COLSPAN = 4,
                                                        .content = to_graphs_parameters.element_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                            .container_index =
#endif
                                                                container_index,
#ifndef __EMSCRIPTEN__
                                                            .member_name =
#endif
                                                                u8"element",
#ifndef __EMSCRIPTEN__
                                                            .datum =
#endif
                                                                *p_tree_node->p_element(),
#ifndef __EMSCRIPTEN__
                                                            .converter_generated_statements_back_inserter =
#endif
                                                                std::back_inserter(converter_generated_statements),
                                                        }),
                                                    },
                                                }});
                                                break;
                                            case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_left_leftmost_descendent_of_root:
                                                result.push_back(
                                                    row_t{{
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .BORDER = 2,
                                                            .COLSPAN = 2,
                                                            .PORT = u8"my_list_begin",
                                                            .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"my_list_begin", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->my_list_begin())}), textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF", .FACE = u8"Cambria Math"}, text_t{{{rb2p_node_role_symbols.at(p_tree_node->role())}}})})},
                                                        },
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 2,
                                                            .PORT = u8"next",
                                                            .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->next())}))},
                                                        },
                                                    }});
                                                if constexpr(static_cast<augmented_sequence_size_management_e>(typename container_t::augmented_sequence_size_management_t{}) == augmented_sequence_size_management_e::at_each_node_except_node_end)
                                                    result.push_back(
                                                        row_t{{
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 4,
                                                                .PORT = u8"node_count",
                                                                .content = html_label_t{text_t{{{u8"n:"}, {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << p_tree_node->node_count).str().data()))}}}},
                                                            },
                                                        }});
                                                if constexpr(!std::is_same_v<typename container_t::accumulated_storage_t, void>)
                                                    result.push_back(row_t{{
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 4,
                                                            .content = to_graphs_parameters.accumulated_storage_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .container_index =
#endif
                                                                    container_index,
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
                                                        .COLSPAN = 4,
                                                        .content = to_graphs_parameters.element_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                            .container_index =
#endif
                                                                container_index,
#ifndef __EMSCRIPTEN__
                                                            .member_name =
#endif
                                                                u8"element",
#ifndef __EMSCRIPTEN__
                                                            .datum =
#endif
                                                                *p_tree_node->p_element(),
#ifndef __EMSCRIPTEN__
                                                            .converter_generated_statements_back_inserter =
#endif
                                                                std::back_inserter(converter_generated_statements),
                                                        }),
                                                    },
                                                }});
                                                break;
                                            case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_not_a_rightmost_descendent:
                                                if constexpr(static_cast<augmented_sequence_size_management_e>(typename container_t::augmented_sequence_size_management_t{}) == augmented_sequence_size_management_e::at_each_node_except_node_end)
                                                    result.push_back(
                                                        row_t{{
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 4,
                                                                .PORT = u8"node_count",
                                                                .content = html_label_t{text_t{{{u8"n:"}, {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << p_tree_node->node_count).str().data()))}}}},
                                                            },
                                                        }});
                                                if constexpr(!std::is_same_v<typename container_t::accumulated_storage_t, void>)
                                                    result.push_back(row_t{{
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 4,
                                                            .content = to_graphs_parameters.accumulated_storage_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .container_index =
#endif
                                                                    container_index,
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
                                                        .COLSPAN = 4,
                                                        .content = to_graphs_parameters.element_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                            .container_index =
#endif
                                                                container_index,
#ifndef __EMSCRIPTEN__
                                                            .member_name =
#endif
                                                                u8"element",
#ifndef __EMSCRIPTEN__
                                                            .datum =
#endif
                                                                *p_tree_node->p_element(),
#ifndef __EMSCRIPTEN__
                                                            .converter_generated_statements_back_inserter =
#endif
                                                                std::back_inserter(converter_generated_statements),
                                                        }),
                                                    },
                                                }});
                                                result.push_back(
                                                    row_t{{
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 2,
                                                            .PORT = u8"next",
                                                            .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->next())}))},
                                                        },
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .BORDER = 2,
                                                            .COLSPAN = 2,
                                                            .PORT = u8"my_list_begin",
                                                            .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"my_list_begin", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->my_list_begin())}), textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF", .FACE = u8"Cambria Math"}, text_t{{{rb2p_node_role_symbols.at(p_tree_node->role())}}})})},
                                                        },
                                                    }});
                                                break;
                                            case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_non_root:
                                                result.push_back(
                                                    row_t{{
                                                        cell_t{
                                                            .COLOR = u8"transparent",
                                                            .COLSPAN = 4,
                                                        },
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .BORDER = 2,
                                                            .COLSPAN = 2,
                                                            .PORT = u8"my_list_begin",
                                                            .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"my_list_begin", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->my_list_begin())}), textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF", .FACE = u8"Cambria Math"}, text_t{{{rb2p_node_role_symbols.at(p_tree_node->role())}}})})},
                                                        },
                                                    }});
                                                if constexpr(static_cast<augmented_sequence_size_management_e>(typename container_t::augmented_sequence_size_management_t{}) == augmented_sequence_size_management_e::at_each_node_except_node_end)
                                                    result.push_back(
                                                        row_t{{
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                                .COLSPAN = 2,
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 4,
                                                                .PORT = u8"node_count",
                                                                .content = html_label_t{text_t{{{u8"n:"}, {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << p_tree_node->node_count).str().data()))}}}},
                                                            },
                                                        }});
                                                if constexpr(!std::is_same_v<typename container_t::accumulated_storage_t, void>)
                                                    result.push_back(row_t{{
                                                        cell_t{
                                                            .COLOR = u8"transparent",
                                                            .COLSPAN = 2,
                                                        },
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 4,
                                                            .content = to_graphs_parameters.accumulated_storage_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .container_index =
#endif
                                                                    container_index,
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
                                                        .PORT = u8"next",
                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->next())}))},
                                                    },
                                                    cell_t{
                                                        .BGCOLOR = active_cell_color,
                                                        .COLSPAN = 4,
                                                        .content = to_graphs_parameters.element_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                            .container_index =
#endif
                                                                container_index,
#ifndef __EMSCRIPTEN__
                                                            .member_name =
#endif
                                                                u8"element",
#ifndef __EMSCRIPTEN__
                                                            .datum =
#endif
                                                                *p_tree_node->p_element(),
#ifndef __EMSCRIPTEN__
                                                            .converter_generated_statements_back_inserter =
#endif
                                                                std::back_inserter(converter_generated_statements),
                                                        }),
                                                    },
                                                }});
                                                break;
                                            case detail::augmented_sequence_rb2p::rb2p_node_role_e::child_right_rightmost_descendent_of_root:
                                                result.push_back(
                                                    row_t{{
                                                        cell_t{
                                                            .COLOR = u8"transparent",
                                                            .COLSPAN = 4,
                                                        },
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .BORDER = 2,
                                                            .COLSPAN = 2,
                                                            .PORT = u8"my_list_begin",
                                                            .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"my_list_begin", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->my_list_begin())}), textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF", .FACE = u8"Cambria Math"}, text_t{{{rb2p_node_role_symbols.at(p_tree_node->role())}}})})},
                                                        },
                                                    }});
                                                if constexpr(static_cast<augmented_sequence_size_management_e>(typename container_t::augmented_sequence_size_management_t{}) == augmented_sequence_size_management_e::at_each_node_except_node_end)
                                                    result.push_back(
                                                        row_t{{
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                                .COLSPAN = 2,
                                                            },
                                                            cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 4,
                                                                .PORT = u8"node_count",
                                                                .content = html_label_t{text_t{{{u8"n:"}, {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << p_tree_node->node_count).str().data()))}}}},
                                                            },
                                                        }});
                                                if constexpr(!std::is_same_v<typename container_t::accumulated_storage_t, void>)
                                                    result.push_back(row_t{{
                                                        cell_t{
                                                            .COLOR = u8"transparent",
                                                            .COLSPAN = 2,
                                                        },
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 4,
                                                            .content = to_graphs_parameters.accumulated_storage_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .container_index =
#endif
                                                                    container_index,
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
                                                        .PORT = u8"next",
                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->next())}))},
                                                    },
                                                    cell_t{
                                                        .BGCOLOR = active_cell_color,
                                                        .COLSPAN = 4,
                                                        .content = to_graphs_parameters.element_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                            .container_index =
#endif
                                                                container_index,
#ifndef __EMSCRIPTEN__
                                                            .member_name =
#endif
                                                                u8"element",
#ifndef __EMSCRIPTEN__
                                                            .datum =
#endif
                                                                *p_tree_node->p_element(),
#ifndef __EMSCRIPTEN__
                                                            .converter_generated_statements_back_inserter =
#endif
                                                                std::back_inserter(converter_generated_statements),
                                                        }),
                                                    },
                                                }});
                                                break;
                                            default:
                                                std::unreachable();
                                                break;
                                            }
                                            return result; //
                                        }(),
                                    }}}},
                    }}});

                if(p_tree_node->child_right() != nullptr && !tagged_ptr_bit0_is_setted(p_tree_node->child_right()))
                    tree_node_recursive(static_cast<typename container_t::node_t *>(static_cast<typename container_t::navigator_t *>(p_tree_node->child_right())), !p_tree_node->color() ? std::make_optional(std::ref(tree_nodes_black_this)) : std::nullopt);

                if(!p_tree_node->color())
                {
                    tree_node_clusters.push_back(subgraph_t{
                        .name = u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"_cluster",
                        .statements = {
                            attr_t{u8"label", u8""},
                            attr_t{u8"id", u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"_cluster"},
                            attr_t{u8"cluster", u8"true"},
                            //                        attr_t{u8"rank", u8"same"},
                        },
                    });
                    tree_node_clusters.back().statements.insert(tree_node_clusters.back().statements.end(), tree_nodes_black_this.rbegin(), tree_nodes_black_this.rend());
                }
            };
            if(typename container_t::navigator_t *node_root_navigator = augmented_sequence_rb2p.node_end->parent_all(); node_root_navigator != tagged_ptr_bit0_setted(augmented_sequence_rb2p.node_end))
                tree_node_recursive(static_cast<typename container_t::node_t *>(tagged_ptr_bit0_unsetted(node_root_navigator)), std::nullopt);

            //        std::ranges::copy(tree_nodes, std::back_inserter(g.statements));
            std::ranges::copy(tree_node_clusters, std::back_inserter(g.statements));
            g.statements.push_back(tree_node_end);
            std::ranges::copy(tree_node_edges, std::back_inserter(g.statements));
            std::ranges::copy(tree_node_end_edges, std::back_inserter(g.statements));

            if constexpr(!std::is_same_v<typename container_t::accumulated_storage_t, void>)
            {
                if(to_graphs_parameters.read_range &&
                    to_graphs_parameters.iterators.size() >= 2 * container_index &&
                    to_graphs_parameters.iterators_container_index[2 * container_index + 0] == container_index && to_graphs_parameters.iterators_container_index[2 * container_index + 1] == container_index &&
                    std::ranges::distance(augmented_sequence_rb2p.begin(), to_graphs_parameters.iterators[2 * container_index + 0]) <= std::ranges::distance(augmented_sequence_rb2p.begin(), to_graphs_parameters.iterators[2 * container_index + 1]))
                {
                    read_range_accumulated_storages.statements.push_back(node_statement_t{{u8"read_range_" + object_pointer_to_string(p_node_end)},
                        {{
                            {u8"id", u8"read_range_" + object_pointer_to_string(p_node_end)},
                            {u8"label", to_graphs_parameters.accumulated_storage_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                            .container_index =
#endif
                                                container_index,
#ifndef __EMSCRIPTEN__
                                            .member_name =
#endif
                                                u8"read_range(it[" + index_to_string(2 * container_index + 0) + u8"], it[" + index_to_string(2 * container_index + 1) + u8"])",
#ifndef __EMSCRIPTEN__
                                            .datum =
#endif
                                                augmented_sequence_rb2p.read_range(to_graphs_parameters.iterators[2 * container_index + 0], to_graphs_parameters.iterators[2 * container_index + 1]),
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
        }

        g.statements.push_back(read_range_accumulated_storages);

        std::vector<node_statement_t> iterator_nodes;
        std::vector<edge_statement_t> iterator_edges;

        std::ranges::for_each(to_graphs_parameters.iterators, [&, index = 0](auto iterator) mutable
            {
                iterator_nodes.push_back(node_statement_t{{u8"it[" + index_to_string(index) + u8"]"},
                    {{
                        {u8"id", u8"it[" + index_to_string(index) + u8"]"},
                        {u8"label", u8"it[" + index_to_string(index) + u8"]" + [&]() -> std::u8string
                            {if constexpr(container_t::iterator_t::support_random_access)return u8"\\l.index():"+index_to_string(iterator.index());else return u8""; }()},
                    }}});
                iterator_edges.push_back(edge_statement_t{{{
                                                              node_id_t{u8"tree_node_" + object_pointer_to_string(iterator.current_node)},
                                                              node_id_t{u8"it[" + index_to_string(index) + u8"]", std::nullopt, c},
                                                          }},
                    {{
                        {u8"id", u8"it[" + index_to_string(index) + u8"]" + u8"->tree_node"},
                        {u8"dir", u8"back"},
                        //                            {u8"constraint", u8"false"},
                    }}});
                ++index; //
            });
        if constexpr(!std::is_same_v<decltype(to_graphs_parameters.iterators_output), std::nullopt_t>)
        {
            std::ranges::for_each(to_graphs_parameters.iterators_output, [&, index = 0](auto iterator) mutable
                {
                    iterator_nodes.push_back(node_statement_t{{u8"jt[" + index_to_string(index) + u8"]"},
                        {{
                            {u8"id", u8"jt[" + index_to_string(index) + u8"]"},
                            {u8"label", u8"jt[" + index_to_string(index) + u8"]"},
                        }}});
                    iterator_edges.push_back(edge_statement_t{{{
                                                                  node_id_t{u8"tree_node_" + object_pointer_to_string(iterator.current_node)},
                                                                  node_id_t{u8"jt[" + index_to_string(index) + u8"]", std::nullopt, c},
                                                              }},
                        {{
                            {u8"id", u8"jt[" + index_to_string(index) + u8"]" + u8"->tree_node"},
                            {u8"dir", u8"back"},
                        }}});
                    ++index; //
                });
        }

        std::ranges::copy(iterator_nodes, std::back_inserter(g.statements));
        std::ranges::copy(iterator_edges, std::back_inserter(g.statements));

        std::ranges::copy(converter_generated_statements, std::back_inserter(g.statements));

        return {g};
    }
} // namespace augmented_containers

#endif // AUGMENTED_RB2P_VISUALIZATION_HPP
