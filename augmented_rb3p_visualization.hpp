#ifndef AUGMENTED_RB3P_VISUALIZATION_HPP
#define AUGMENTED_RB3P_VISUALIZATION_HPP

#include "augmented_rb3p.hpp"
#include "ext_infrastructure/ext_graphviz.hpp"
#include <sstream>
#include <iomanip>
#include <functional>
#include <optional>

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
    #ifdef __EMSCRIPTEN__
                std::byte const(&r)[sizeof(T)] = reinterpret_cast<std::byte const(&)[sizeof(T)]>(print_pointer.p);
                std::for_each(std::begin(r), std::end(r), [&](std::byte const &b)
                    { os << "0x" << std::hex << std::setw(2) << std::setfill('0') << (int)b << std::dec << std::setw(0) << std::setfill(' '); });
    #else
                std::ranges::for_each(reinterpret_cast<std::byte const(&)[sizeof(T)]>(print_pointer.p), [&](std::byte const &b)
                    { os << "0x" << std::hex << std::setw(2) << std::setfill('0') << (int)b << std::dec << std::setw(0) << std::setfill(' '); });
    #endif
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

            namespace augmented_sequence_rb3p
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
            } // namespace augmented_sequence_rb3p
        } // namespace visualization
    } // namespace detail
    template<typename element_t, typename allocator_element_t, typename accumulator_t, typename size_management_t, typename... to_graphs_parameters_t_parameters_t>
    std::vector<dot::graph_t> to_graphs(std::vector<augmented_sequence_t<element_t, allocator_element_t, accumulator_t, std::integral_constant<augmented_sequence_physical_representation_e, augmented_sequence_physical_representation_e::rb3p>, size_management_t>> const &augmented_sequence_rb3p_s, detail::visualization::augmented_sequence_rb3p::to_graphs_parameters_t<to_graphs_parameters_t_parameters_t...> to_graphs_parameters)
    {
        using namespace dot;
        using namespace detail::language;
        using namespace detail::visualization;
        using namespace detail::visualization::augmented_sequence_rb3p;

        using container_t = std::remove_cvref_t<decltype(augmented_sequence_rb3p_s)>::value_type;

        constexpr bool generating_title = false;

        std::vector<std::variant<node_statement_t, edge_statement_t, attr_statement_t, attr_t, subgraph_t>> converter_generated_statements;

        graph_t g{
            .is_strict = false,
            .is_directed = true,
            .name = std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "augmented_sequence_rb3p").str().data())),
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

        for(container_t const &augmented_sequence_rb3p : augmented_sequence_rb3p_s)
        {
            typename container_t::node_end_t *p_node_end = tagged_ptr_bit0_unsetted(augmented_sequence_rb3p.node_end);
            std::size_t container_index = &augmented_sequence_rb3p - &augmented_sequence_rb3p_s[0];

            std::vector<edge_statement_t> tree_node_end_edges;

            if(tagged_ptr_bit0_unsetted(p_node_end->parent()) != p_node_end)
            {
                assert(p_node_end->child_right() != nullptr);
                assert(tagged_ptr_bit0_is_setted(p_node_end->child_right()));
                tree_node_end_edges.push_back(edge_statement_t{{{
                                                                   node_id_t{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_right", std::nullopt, c},
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted(p_node_end->child_right()))},
                                                               }},
                    {{
                        {u8"id", u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"->child_right"},
                        {u8"style", tagged_ptr_bit0_is_setted(p_node_end->child_right()) ? u8"dashed" : u8"solid"},
                        {u8"constraint", u8"false"},
                        {u8"tailclip", u8"false"},
                    }}});

                assert(p_node_end->parent() != nullptr);
                assert(tagged_ptr_bit0_is_setted(p_node_end->parent()));
                tree_node_end_edges.push_back(edge_statement_t{{{
                                                                   node_id_t{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_parent", std::nullopt, c},
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted(p_node_end->parent()))},
                                                               }},
                    {{
                        {u8"id", u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"->parent"},
                        {u8"style", tagged_ptr_bit0_is_setted(p_node_end->parent()) ? u8"dashed" : u8"solid"},
                        {u8"constraint", u8"true"},
                        {u8"tailclip", u8"false"},
                    }}});

                assert(p_node_end->child_left() != nullptr);
                assert(tagged_ptr_bit0_is_setted(p_node_end->child_left()));
                tree_node_end_edges.push_back(edge_statement_t{{{
                                                                   node_id_t{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_left", std::nullopt, c},
                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted(p_node_end->child_left()))},
                                                               }},
                    {{
                        {u8"id", u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"->child_left"},
                        {u8"style", tagged_ptr_bit0_is_setted(p_node_end->child_left()) ? u8"dashed" : u8"solid"},
                        {u8"constraint", u8"false"},
                        {u8"tailclip", u8"false"},
                    }}});
            }

            node_statement_t tree_node_end_members_render_from_left_to_right_node{{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_members_render_from_left_to_right"},
                {{
                    {u8"id", u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_members_render_from_left_to_right"},
                    {u8"ordering", u8"out"},
                    {u8"label", u8""},
                }}};
            tree_node_end_edges.push_back(edge_statement_t{{{
                                                               node_id_t{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_members_render_from_left_to_right"},
                                                               node_id_t{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_right"},
                                                           }},
                {{
                    {u8"id", u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_members_render_from_left_to_right" + u8"->tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_right"},
                    {u8"constraint", u8"true"},
                    {u8"tailclip", u8"false"},
                    {u8"color", u8"transparent"},
                }}});
            tree_node_end_edges.push_back(edge_statement_t{{{
                                                               node_id_t{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_members_render_from_left_to_right"},
                                                               node_id_t{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_parent"},
                                                           }},
                {{
                    {u8"id", u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_members_render_from_left_to_right" + u8"->tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_parent"},
                    {u8"constraint", u8"true"},
                    {u8"tailclip", u8"false"},
                    {u8"color", u8"transparent"},
                }}});
            tree_node_end_edges.push_back(edge_statement_t{{{
                                                               node_id_t{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_members_render_from_left_to_right"},
                                                               node_id_t{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_left"},
                                                           }},
                {{
                    {u8"id", u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_members_render_from_left_to_right" + u8"->tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_left"},
                    {u8"constraint", u8"true"},
                    {u8"tailclip", u8"false"},
                    {u8"color", u8"transparent"},
                }}});
            subgraph_t tree_node_end_subgraph{
                .name = u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_cluster",
                .statements = {
                    attr_t{u8"label", u8""},
                    attr_t{u8"id", u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_cluster"},
                    attr_t{u8"rank", u8"same"},
                },
            };
            tree_node_end_subgraph.statements.push_back(node_statement_t{{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_right"},
                {{
                    {u8"id", u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_right"},
                    {u8"label", html_label_t{fonttable_t{table_t{
                                    .BORDER = 0,
                                    .CELLBORDER = 1,
                                    .CELLSPACING = 0,
                                    .COLOR = u8"#888888",
                                    .rows = [&]()
                                    { return decltype(table_t::rows){
                                          row_t{{
                                              cell_t{
                                                  .BGCOLOR = tagged_ptr_bit0_unsetted(p_node_end->parent()) != p_node_end ? active_cell_color : inactive_cell_color,
                                                  .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"child_right", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_node_end->child_right())}))},
                                              },
                                          }},
                                      }; }(),
                                }}}},
                }}});
            tree_node_end_subgraph.statements.push_back(node_statement_t{{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_parent"},
                {{
                    {u8"id", u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_parent"},
                    {u8"label", html_label_t{fonttable_t{table_t{
                                    .BORDER = 0,
                                    .CELLBORDER = 1,
                                    .CELLSPACING = 0,
                                    .COLOR = u8"#888888",
                                    .rows = [&]()
                                    {
                                         decltype(table_t::rows)result;

                                         if constexpr(static_cast<augmented_sequence_size_management_e>(typename container_t::augmented_sequence_size_management_t{}) == augmented_sequence_size_management_e::at_node_end)
                                         {
                                             return decltype(table_t::rows){
                                                 row_t{{
                                                     cell_t{
                                                         .BGCOLOR = active_cell_color,
                                                         .COLSPAN = 4,
                                                         .PORT = u8"node_count",
                                                         .content = html_label_t{text_t{{{u8"n:"}, {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << p_node_end->node_count).str().data()))}}}},
                                                     },
                                                 }},
                                                 row_t{{
                                                       cell_t{
                                                           .COLOR = u8"transparent",
                                                       },
                                                       cell_t{
                                                           .BGCOLOR = tagged_ptr_bit0_unsetted(p_node_end->parent()) != p_node_end ? active_cell_color : inactive_cell_color,
                                                            .COLSPAN = 2,
                                                           .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"parent", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_node_end->parent())}))},
                                                       },
                                                       cell_t{
                                                           .COLOR = u8"transparent",
                                                       },
                                                   }},
                                             };
                                         }
                                         else
                                         {
                                            return decltype(table_t::rows){
                                                         row_t{{
                                                             cell_t{
                                                                 .BGCOLOR = tagged_ptr_bit0_unsetted(p_node_end->parent()) != p_node_end ? active_cell_color : inactive_cell_color,
                                                                 .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"parent", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_node_end->parent())}))},
                                                             },
                                                         }},
                                                     };
                                         } }(),
                                }}}},
                }}});
            tree_node_end_subgraph.statements.push_back(node_statement_t{{u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_left"},
                {{
                    {u8"id", u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_left"},
                    {u8"label", html_label_t{fonttable_t{table_t{
                                    .BORDER = 0,
                                    .CELLBORDER = 1,
                                    .CELLSPACING = 0,
                                    .COLOR = u8"#888888",
                                    .rows = [&]()
                                    { return decltype(table_t::rows){
                                          row_t{{
                                              cell_t{
                                                  .BGCOLOR = tagged_ptr_bit0_unsetted(p_node_end->parent()) != p_node_end ? active_cell_color : inactive_cell_color,
                                                  .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"child_left", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_node_end->child_left())}))},
                                              },
                                          }},
                                      }; }(),
                                }}}},
                }}});

            std::vector<subgraph_t> tree_node_clusters;
            std::vector<edge_statement_t> tree_node_edges;

            std::function<void(typename container_t::node_t *, std::optional<std::reference_wrapper<std::vector<node_statement_t>>>)> tree_node_recursive = [&](typename container_t::node_t *p_tree_node, std::optional<std::reference_wrapper<std::vector<node_statement_t>>> tree_nodes_from_black_parent)
            {
                //                qDebug() << *p_tree_node;

                assert(!(p_tree_node->child_left() != nullptr && tagged_ptr_bit0_is_setted(p_tree_node->child_left())) || p_tree_node->child_left() == augmented_sequence_rb3p.node_end);
                if(p_tree_node->child_left() != nullptr //
                    //                    && !tagged_ptr_bit0_is_setted(p_tree_node->child_left()) //
                )
                {
                    (!tagged_ptr_bit0_is_setted(p_tree_node->child_left()) ? tree_node_edges : tree_node_end_edges)
                        .push_back(edge_statement_t{{{
                                                        node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"child_left", c},
                                                        node_id_t{tagged_ptr_bit0_is_setted(p_tree_node->child_left()) ? u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_right" : u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->child_left()))},
                                                    }},
                            {{
                                {u8"id", tagged_ptr_bit0_is_setted(p_tree_node->child_left()) ? u8"child_right->tree_node_end_" + object_pointer_to_string(p_node_end) : u8"parent->" + (u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->child_left())))},
                                {u8"style", tagged_ptr_bit0_is_setted(p_tree_node->child_left()) ? u8"dashed" : u8"solid"},
                                {u8"constraint", !tagged_ptr_bit0_is_setted(p_tree_node->child_left()) ? (!p_tree_node->color() && p_tree_node->child_left()->color() ? u8"false" : u8"true") /*u8"true"*/ : u8"false"},
                                {u8"tailclip", u8"false"},
                            }}});
                }

                assert(p_tree_node->parent() != nullptr);
                assert(!tagged_ptr_bit0_is_setted(p_tree_node->parent()) || p_tree_node->parent() == augmented_sequence_rb3p.node_end);
                if(true //
                    //                    && !tagged_ptr_bit0_is_setted(p_tree_node->parent()) //
                )
                {
                    (!tagged_ptr_bit0_is_setted(p_tree_node->parent()) ? tree_node_edges : tree_node_end_edges)
                        .push_back(edge_statement_t{{{
                                                        node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"parent", c},
                                                        node_id_t{tagged_ptr_bit0_is_setted(p_tree_node->parent()) ? u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_parent" : u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->parent()))},
                                                    }},
                            {{
                                {u8"id", tagged_ptr_bit0_is_setted(p_tree_node->parent()) ? u8"parent->tree_node_end_" + object_pointer_to_string(p_node_end) : u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"->parent"},
                                {u8"style", tagged_ptr_bit0_is_setted(p_tree_node->parent()) ? u8"dashed" : u8"solid"},
                                {u8"constraint", u8"false"},
                                {u8"tailclip", u8"false"},
                            }}});
                }

                assert(!(p_tree_node->child_right() != nullptr && tagged_ptr_bit0_is_setted(p_tree_node->child_right())) || p_tree_node->child_right() == augmented_sequence_rb3p.node_end);
                if(p_tree_node->child_right() != nullptr //
                    //                    && !tagged_ptr_bit0_is_setted(p_tree_node->child_right()) //
                )
                {
                    (!tagged_ptr_bit0_is_setted(p_tree_node->child_right()) ? tree_node_edges : tree_node_end_edges)
                        .push_back(edge_statement_t{{{
                                                        node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"child_right", c},
                                                        node_id_t{tagged_ptr_bit0_is_setted(p_tree_node->child_right()) ? u8"tree_node_end_" + object_pointer_to_string(p_node_end) + u8"_child_left" : u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->child_right()))},
                                                    }},
                            {{
                                {u8"id", tagged_ptr_bit0_is_setted(p_tree_node->child_right()) ? u8"child_left->tree_node_end_" + object_pointer_to_string(p_node_end) : u8"parent->" + (u8"tree_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted_relaxed(p_tree_node->child_right())))},
                                {u8"style", tagged_ptr_bit0_is_setted(p_tree_node->child_right()) ? u8"dashed" : u8"solid"},
                                {u8"constraint", !tagged_ptr_bit0_is_setted(p_tree_node->child_right()) ? (!p_tree_node->color() && p_tree_node->child_right()->color() ? u8"false" : u8"true") /*u8"true"*/ : u8"false"},
                                {u8"tailclip", u8"false"},
                            }}});
                }

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
                                            result.push_back(
                                                row_t{{
                                                    cell_t{
                                                        .COLOR = u8"transparent",
                                                    },
                                                    cell_t{
                                                        .BGCOLOR = !tagged_ptr_bit0_is_setted(p_tree_node->parent()) ? active_cell_color : inactive_cell_color,
                                                        .COLSPAN = 2,
                                                        .PORT = u8"parent",
                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"parent", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->parent())}))},
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
                                                    .BGCOLOR = p_tree_node->child_left() != nullptr && !tagged_ptr_bit0_is_setted(p_tree_node->child_left()) ? active_cell_color : inactive_cell_color,
                                                    .COLSPAN = 2,
                                                    .PORT = u8"child_left",
                                                    .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"child_left", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->child_left())}))},
                                                },
                                                cell_t{
                                                    .BGCOLOR = p_tree_node->child_right() != nullptr && !tagged_ptr_bit0_is_setted(p_tree_node->child_right()) ? active_cell_color : inactive_cell_color,
                                                    .COLSPAN = 2,
                                                    .PORT = u8"child_right",
                                                    .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"child_right", print_object_pointer_t{static_cast<typename container_t::navigator_t *>(p_tree_node->child_right())}))},
                                                },
                                            }});
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
            if(auto node_root_navigator = container_t::navigator_t::untagged_root_or_tagged_end(augmented_sequence_rb3p.node_end); !tagged_ptr_bit0_is_setted(node_root_navigator))
                tree_node_recursive(static_cast<typename container_t::node_t *>(node_root_navigator), std::nullopt);

#ifdef __EMSCRIPTEN__
            //        std::copy(tree_nodes.begin(), tree_nodes.end(), std::back_inserter(g.statements));
            std::copy(tree_node_clusters.begin(), tree_node_clusters.end(), std::back_inserter(g.statements));
            //g.statements.push_back(tree_node_end);
            g.statements.push_back(tree_node_end_members_render_from_left_to_right_node);
            g.statements.push_back(tree_node_end_subgraph);
            std::copy(tree_node_edges.begin(), tree_node_edges.end(), std::back_inserter(g.statements));
            std::copy(tree_node_end_edges.begin(), tree_node_end_edges.end(), std::back_inserter(g.statements));
#else
            //        std::ranges::copy(tree_nodes, std::back_inserter(g.statements));
            std::ranges::copy(tree_node_clusters, std::back_inserter(g.statements));
            //g.statements.push_back(tree_node_end);
            g.statements.push_back(tree_node_end_members_render_from_left_to_right_node);
            g.statements.push_back(tree_node_end_subgraph);
            std::ranges::copy(tree_node_edges, std::back_inserter(g.statements));
            std::ranges::copy(tree_node_end_edges, std::back_inserter(g.statements));
#endif

            if constexpr(!std::is_same_v<typename container_t::accumulated_storage_t, void>)
            {
                if(to_graphs_parameters.read_range &&
                    to_graphs_parameters.iterators.size() >= 2 * container_index &&
                    to_graphs_parameters.iterators_container_index[2 * container_index + 0] == container_index && to_graphs_parameters.iterators_container_index[2 * container_index + 1] == container_index &&
                    std::ranges::distance(augmented_sequence_rb3p.begin(), to_graphs_parameters.iterators[2 * container_index + 0]) <= std::ranges::distance(augmented_sequence_rb3p.begin(), to_graphs_parameters.iterators[2 * container_index + 1]))
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
                                                augmented_sequence_rb3p.read_range(to_graphs_parameters.iterators[2 * container_index + 0], to_graphs_parameters.iterators[2 * container_index + 1]),
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
#ifdef __EMSCRIPTEN__
        std::for_each(to_graphs_parameters.iterators.begin(), to_graphs_parameters.iterators.end(), [&, index = 0](auto iterator) mutable
            {
                if(std::none_of(augmented_sequence_rb3p_s.begin(), augmented_sequence_rb3p_s.end(), [&](container_t const &augmented_sequence_rb3p)
                       { return iterator.current_node == augmented_sequence_rb3p.end(); }))
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
                        }}});
                }
                ++index; //
            });
#else
        std::ranges::for_each(to_graphs_parameters.iterators, [&, index = 0](auto iterator) mutable
            {
                if(std::ranges::none_of(augmented_sequence_rb3p_s, [&](container_t const &augmented_sequence_rb3p)
                       { return iterator.current_node == augmented_sequence_rb3p.end(); }))
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
                        }}});
                }
                ++index; //
            });
#endif
        if constexpr(!std::is_same_v<decltype(to_graphs_parameters.iterators_output), std::nullopt_t>)
        {
#ifdef __EMSCRIPTEN__
            std::for_each(to_graphs_parameters.iterators_output.begin(), to_graphs_parameters.iterators_output.end(), [&, index = 0](auto iterator) mutable
                {
                    if(std::ranges::none_of(augmented_sequence_rb3p_s, [&](container_t const &augmented_sequence_rb3p)
                           { return iterator.current_node == augmented_sequence_rb3p.end(); }))
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
                    }
                    ++index; //
                });
#else
            std::ranges::for_each(to_graphs_parameters.iterators_output, [&, index = 0](auto iterator) mutable
                {
                    if(std::ranges::none_of(augmented_sequence_rb3p_s, [&](container_t const &augmented_sequence_rb3p)
                           { return iterator.current_node == augmented_sequence_rb3p.end(); }))
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
                    }
                    ++index; //
                });
#endif
        }

#ifdef __EMSCRIPTEN__
        std::copy(iterator_nodes.begin(), iterator_nodes.end(), std::back_inserter(g.statements));
        std::copy(iterator_edges.begin(), iterator_edges.end(), std::back_inserter(g.statements));
#else
        std::ranges::copy(iterator_nodes, std::back_inserter(g.statements));
        std::ranges::copy(iterator_edges, std::back_inserter(g.statements));
#endif

#ifdef __EMSCRIPTEN__
        std::copy(converter_generated_statements.begin(), converter_generated_statements.end(), std::back_inserter(g.statements));
#else
        std::ranges::copy(converter_generated_statements, std::back_inserter(g.statements));
#endif

        return {g};
    }
} // namespace augmented_containers

#endif // AUGMENTED_RB3P_VISUALIZATION_HPP
