#ifndef AUGMENTED_GRAPH_VISUALIZATION_HPP
#define AUGMENTED_GRAPH_VISUALIZATION_HPP

#include <augmented_containers/augmented_graph.hpp>
#include <ext_infrastructure/ext_graphviz.hpp>
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

            namespace augmented_graph
            {
                enum class storage_node_type_e { uninitialized,
                    vertex,
                    edge,
                    top_tree_graph_vertex,
                    top_tree_graph_edge,
                    top_tree_graph_hierarchy_vertex,
                    top_tree_graph_hierarchy_edge,
                    top_tree_graph_hierarchy_cluster_title_vertex,
                    top_tree_graph_hierarchy_cluster_title_cluster,
                    top_tree_cluster_hierarchy_vertex,
                    top_tree_cluster_hierarchy_cluster };

                template<typename datum_t, typename converter_generated_statements_back_inserter_t>
                struct to_string_converter_parameters_t
                {
                    std::u8string const &member_name;
                    datum_t const &datum;
                    converter_generated_statements_back_inserter_t converter_generated_statements_back_inserter;
                    storage_node_type_e accumulated_storage_node_type;
                };
#if __cpp_deduction_guides >= 201907L
#else
                template<typename datum_t, typename converter_generated_statements_back_inserter_t>
                to_string_converter_parameters_t(std::u8string const &, datum_t const &, converter_generated_statements_back_inserter_t, storage_node_type_e) -> to_string_converter_parameters_t<datum_t, converter_generated_statements_back_inserter_t>;
#endif

                template<typename vertex_to_string_converter_t, typename edge_to_string_converter_t, typename part_data_to_string_converter_per_part_t, typename iterators_vertex_t, typename iterators_edge_t>
                struct to_graphs_parameters_t
                {
                    vertex_to_string_converter_t vertex_to_string_converter;
                    edge_to_string_converter_t edge_to_string_converter;
                    part_data_to_string_converter_per_part_t part_data_to_string_converter_per_part;
                    iterators_vertex_t iterators_vertex;
                    iterators_edge_t iterators_edge;
                };
#if __cpp_deduction_guides >= 201907L
#else
                template<typename... T>
                to_graphs_parameters_t(T...) -> to_graphs_parameters_t<T...>;
#endif
            } // namespace augmented_graph
        } // namespace visualization
    } // namespace detail

    template<typename vertex_t, typename edge_t, typename parts_data_structure_and_parameters_t, std::strict_weak_order<vertex_t, vertex_t> comparator_vertex_t, std::strict_weak_order<edge_t, edge_t> comparator_edge_t, typename allocator_vertex_t, typename... to_graphs_parameters_t_parameters_t>
    std::vector<std::vector<dot::graph_t>> to_graphs(
        augmented_graph_t<vertex_t, edge_t, parts_data_structure_and_parameters_t, comparator_vertex_t, comparator_edge_t, allocator_vertex_t> const &augmented_graph,
        detail::visualization::augmented_graph::to_graphs_parameters_t<to_graphs_parameters_t_parameters_t...> to_graphs_parameters)
    {
        using namespace dot;
        using namespace detail::language;
        using namespace detail::visualization;
        using namespace detail::visualization::augmented_graph;

        using container_t = std::remove_cvref_t<decltype(augmented_graph)>;

        constexpr bool generating_title = false;

        std::vector<std::vector<dot::graph_t>> result;

        {
            std::vector<std::variant<node_statement_t, edge_statement_t, attr_statement_t, attr_t, subgraph_t>> converter_generated_statements;

            std::vector<node_statement_t> vertex_nodes;
            std::vector<node_statement_t> edge_nodes;
            std::vector<edge_statement_t> vertex_edge_edges;
            std::vector<node_statement_t> iterator_vertex_nodes;
            std::vector<edge_statement_t> iterator_vertex_edges;
            std::vector<node_statement_t> iterator_edge_nodes;
            std::vector<edge_statement_t> iterator_edge_edges;

            for(typename container_t::it_vertex_t iterator_vertex = augmented_graph.vertexes.begin(); iterator_vertex != augmented_graph.vertexes.end(); ++iterator_vertex)
            {
                vertex_t const *address_vertex = &*iterator_vertex;
                vertex_nodes.push_back(node_statement_t{{u8"vertex_" + object_pointer_to_string(address_vertex)},
                    {{
                        {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex)},
                        {u8"shape", u8"ellipse"},
                        {u8"margin", u8"0.05,0.05"},
                        {u8"style", u8"filled"},
                        {u8"fillcolor", active_cell_color},
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
                                                        .content = html_label_t{pointer_title_text_to_title_only(u8"vertex", object_pointer_to_string(address_vertex))},
                                                    },
                                                }});
                                            result.push_back(row_t{{
                                                cell_t{
                                                    .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                        .member_name =
#endif
                                                            u8"vertex",
#ifndef __EMSCRIPTEN__
                                                        .datum =
#endif
                                                            iterator_vertex,
#ifndef __EMSCRIPTEN__
                                                        .converter_generated_statements_back_inserter =
#endif
                                                            std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                        .accumulated_storage_node_type =
#endif
                                                            storage_node_type_e::vertex,
                                                    }),
                                                },
                                            }});
                                            return result; //
                                        }(),
                                    }}}},
                    }}});

                for(typename container_t::it_edge_it_vertexes_t const &vertex_edge : augmented_graph.it_vertexes_it_edges.at(iterator_vertex))
                {
                    edge_t const *address_edge = &vertex_edge->first;

                    if(vertex_edge->second.first == vertex_edge->second.second)
                    {
                        vertex_edge_edges.push_back(edge_statement_t{{{
                                                                         node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex)},
                                                                         node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                     }},
                            {{
                                {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge1"},
                                {u8"headclip", u8"false"},
                                {u8"dir", u8"none"},
                            }}});
                        vertex_edge_edges.push_back(edge_statement_t{{{
                                                                         node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex)},
                                                                         node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                     }},
                            {{
                                {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge2"},
                                {u8"headclip", u8"false"},
                                {u8"dir", u8"none"},
                            }}});
                    }
                    else
                        vertex_edge_edges.push_back(edge_statement_t{{{
                                                                         node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex)},
                                                                         node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                     }},
                            {{
                                {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge"},
                                {u8"headclip", u8"false"},
                                {u8"dir", u8"none"},
                            }}});

                    if(iterator_vertex == vertex_edge->second.first)
                        edge_nodes.push_back(node_statement_t{{u8"edge_" + object_pointer_to_string(address_edge)},
                            {{
                                {u8"id", u8"edge_" + object_pointer_to_string(address_edge)},
                                {u8"style", u8"filled"},
                                {u8"fillcolor", active_cell_color},
                                {u8"label", html_label_t{fonttable_t{table_t{
                                                .BORDER = 0,
                                                .CELLBORDER = 1,
                                                .CELLSPACING = 0,
                                                .COLOR = u8"#00000060",
                                                .rows = [&]()
                                                {
                                                    decltype(table_t::rows) result;
                                                    if constexpr(generating_title)
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .COLOR = u8"transparent",
                                                                .content = html_label_t{pointer_title_text_to_title_only(u8"edge", object_pointer_to_string(address_edge))},
                                                            },
                                                        }});
                                                    result.push_back(row_t{{
                                                        cell_t{
                                                            .content = to_graphs_parameters.edge_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .member_name =
#endif
                                                                    u8"edge",
#ifndef __EMSCRIPTEN__
                                                                .datum =
#endif
                                                                    vertex_edge,
#ifndef __EMSCRIPTEN__
                                                                .converter_generated_statements_back_inserter =
#endif
                                                                    std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                .accumulated_storage_node_type =
#endif
                                                                    storage_node_type_e::edge,
                                                            }),
                                                        },
                                                    }});
                                                    return result; //
                                                }(),
                                            }}}},
                            }}});
                }
            }

            std::ranges::for_each(to_graphs_parameters.iterators_vertex, [&, index = 0](auto iterator_vertex) mutable
                {
                    if(iterator_vertex != augmented_graph.vertexes.end())
                    {
                        vertex_t const *address_vertex = &*iterator_vertex;
                        iterator_vertex_nodes.push_back(node_statement_t{{u8"itv[" + index_to_string(index) + u8"]"},
                            {{
                                {u8"id", u8"itv[" + index_to_string(index) + u8"]"},
                                {u8"label", u8"itv[" + index_to_string(index) + u8"]"},
                            }}});
                        iterator_vertex_edges.push_back(edge_statement_t{{{
                                                                             node_id_t{u8"itv[" + index_to_string(index) + u8"]"},
                                                                             node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex)},
                                                                         }},
                            {{
                                {u8"id", u8"itv[" + index_to_string(index) + u8"]" + u8"->vertex"},
                            }}});
                    }
                    ++index; //
                });
            std::ranges::for_each(to_graphs_parameters.iterators_edge, [&, index = 0](auto iterator_edge) mutable
                {
                    if(iterator_edge != augmented_graph.edges_it_vertexes.end())
                    {
                        edge_t const *address_edge = &iterator_edge->first;
                        iterator_edge_nodes.push_back(node_statement_t{{u8"ite[" + index_to_string(index) + u8"]"},
                            {{
                                {u8"id", u8"ite[" + index_to_string(index) + u8"]"},
                                {u8"label", u8"ite[" + index_to_string(index) + u8"]"},
                            }}});
                        iterator_edge_edges.push_back(edge_statement_t{{{
                                                                           node_id_t{u8"ite[" + index_to_string(index) + u8"]"},
                                                                           node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                       }},
                            {{
                                {u8"id", u8"ite[" + index_to_string(index) + u8"]" + u8"->edge"},
                            }}});
                    }
                    ++index; //
                });

            graph_t g{
                .is_strict = false,
                .is_directed = true,
                .name = std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "augmented_graph").str().data())),
                .statements = {
                    attr_t{u8"layout", u8"neato"},

                    attr_t{u8"label", u8""},
                    attr_t{u8"id", u8"graph"},

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
                                               {u8"width", u8"0"},
                                               {u8"height", u8"0"},
                                               {u8"margin", u8"0,0"},
                                               {u8"fontname", u8"Consolas"},
                                               {u8"color", u8"#000000"},
                                           }}},
                },
            };

            std::ranges::copy(vertex_nodes, std::back_inserter(g.statements));
            std::ranges::copy(edge_nodes, std::back_inserter(g.statements));
            std::ranges::copy(vertex_edge_edges, std::back_inserter(g.statements));
            std::ranges::copy(iterator_vertex_nodes, std::back_inserter(g.statements));
            std::ranges::copy(iterator_vertex_edges, std::back_inserter(g.statements));
            std::ranges::copy(iterator_edge_nodes, std::back_inserter(g.statements));
            std::ranges::copy(iterator_edge_edges, std::back_inserter(g.statements));

            std::ranges::copy(converter_generated_statements, std::back_inserter(g.statements));

            result.push_back({g});
        }

        [&]<std::size_t... part_index>(std::index_sequence<part_index...>)
        {
            (..., [&]()
                {
                using part_t = typename container_t::template part_t<part_index>;
                part_t const&part=augmented_graph.template part<part_index>();
                if constexpr(container_t::template part_data_structure<part_index> == augmented_containers::augmented_graph_part_data_structure_e::top_tree)
                {
                    std::vector<dot::graph_t>sub_result;

                    {
                        std::vector<std::variant<node_statement_t, edge_statement_t, attr_statement_t, attr_t, subgraph_t>> converter_generated_statements;

                        std::vector<node_statement_t> vertex_nodes;
                        std::vector<node_statement_t> edge_nodes;
                        std::vector<edge_statement_t> vertex_edge_edges;
                        std::vector<node_statement_t> iterator_vertex_nodes;
                        std::vector<edge_statement_t> iterator_vertex_edges;
                        std::vector<node_statement_t> iterator_edge_nodes;
                        std::vector<edge_statement_t> iterator_edge_edges;

                        using it_vertex_t=typename container_t::it_vertex_t;
                        using it_edge_it_vertexes_t=typename container_t::it_edge_it_vertexes_t;

                        auto push_back_vertex_node=[&](it_vertex_t iterator_vertex)
                        {
                            vertex_t const *address_vertex = &*iterator_vertex;
                            vertex_nodes.push_back(node_statement_t{{u8"vertex_" + object_pointer_to_string(address_vertex)},
                                {{
                                    {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex)},
                                    {u8"shape", u8"ellipse"},
                                    {u8"margin", u8"0.05,0.05"},
                                    {u8"style", u8"filled"},
                                    {u8"fillcolor", active_cell_color},
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
                                                                    .content = html_label_t{pointer_title_text_to_title_only(u8"vertex", object_pointer_to_string(address_vertex))},
                                                                },
                                                            }});
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .BORDER=part.it_vertex_exposed1==iterator_vertex||part.it_vertex_exposed2==iterator_vertex?std::make_optional<double>(2):std::nullopt,
                                                                .COLOR=part.it_vertex_exposed1==iterator_vertex||part.it_vertex_exposed2==iterator_vertex?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"vertex",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        iterator_vertex,
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                    .accumulated_storage_node_type =
#endif
                                                                        storage_node_type_e::top_tree_graph_vertex,
                                                                }),
                                                            },
                                                        }});
                                                        return result; //
                                                    }(),
                                                }}}},
                                }}});
                        };
                        auto push_back_iterators_vertex_nodes_and_edges=[&](it_vertex_t current_iterator_vertex)
                        {
                            std::ranges::for_each(to_graphs_parameters.iterators_vertex, [&, index = 0](auto iterator_vertex) mutable
                                {
                                    if(iterator_vertex == current_iterator_vertex)
                                    {
                                        vertex_t const *address_vertex = &*iterator_vertex;
                                        iterator_vertex_nodes.push_back(node_statement_t{{u8"itv[" + index_to_string(index) + u8"]"},
                                            {{
                                                {u8"id", u8"itv[" + index_to_string(index) + u8"]"},
                                                {u8"label", u8"itv[" + index_to_string(index) + u8"]"},
                                            }}});
                                        iterator_vertex_edges.push_back(edge_statement_t{{{
                                                                                            node_id_t{u8"itv[" + index_to_string(index) + u8"]"},
                                                                                            node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex)},
                                                                                        }},
                                            {{
                                                {u8"id", u8"itv[" + index_to_string(index) + u8"]" + u8"->vertex"},
                                            }}});
                                    }
                                    ++index; //
                                });
                        };
                        auto push_back_iterators_edge_nodes_and_edges=[&](it_edge_it_vertexes_t current_iterator_edge)
                        {
                            std::ranges::for_each(to_graphs_parameters.iterators_edge, [&, index = 0](auto iterator_edge) mutable
                                {
                                    if(iterator_edge == current_iterator_edge)
                                    {
                                        edge_t const *address_edge = &iterator_edge->first;
                                        iterator_edge_nodes.push_back(node_statement_t{{u8"ite[" + index_to_string(index) + u8"]"},
                                            {{
                                                {u8"id", u8"ite[" + index_to_string(index) + u8"]"},
                                                {u8"label", u8"ite[" + index_to_string(index) + u8"]"},
                                            }}});
                                        iterator_edge_edges.push_back(edge_statement_t{{{
                                                                                            node_id_t{u8"ite[" + index_to_string(index) + u8"]"},
                                                                                            node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                                        }},
                                            {{
                                                {u8"id", u8"ite[" + index_to_string(index) + u8"]" + u8"->edge"},
                                            }}});
                                    }
                                    ++index; //
                                });
                        };

                        for(it_vertex_t iterator_vertex : part.it_vertexes_trivial_component)
                        {
                            push_back_vertex_node(iterator_vertex);
                            push_back_iterators_vertex_nodes_and_edges(iterator_vertex);
                        }
                        for(it_edge_it_vertexes_t iterator_edge:part.it_edges_fundamental)
                        {
                            vertex_t const *address_vertex1 = &*iterator_edge->second.first;
                            vertex_t const *address_vertex2 = &*iterator_edge->second.second;
                            edge_t const *address_edge = &iterator_edge->first;

                            if(iterator_edge->second.first==iterator_edge->second.second)
                            {
                                vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                 node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex1)},
                                                                                 node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                             }},
                                    {{
                                        {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex1) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge1"},
                                        {u8"headclip", u8"false"},
                                        {u8"dir", u8"none"},
                                    }}});
                                vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                  node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex2)},
                                                                                  node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                             }},
                                    {{
                                        {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex2) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge2"},
                                        {u8"headclip", u8"false"},
                                        {u8"dir", u8"none"},
                                    }}});
                            }
                            else
                            {
                                vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                 node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex1)},
                                                                                 node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                             }},
                                    {{
                                        {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex1) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge"},
                                        {u8"headclip", u8"false"},
                                        {u8"dir", u8"back"},
                                        {u8"arrowsize", u8"0.0002"},
                                    }}});
                                vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                  node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex2)},
                                                                                  node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                             }},
                                    {{
                                        {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex2) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge"},
                                        {u8"headclip", u8"false"},
                                        {u8"dir", u8"back"},
                                        {u8"arrowsize", u8"0.0002"},
                                    }}});
                            }
                            edge_nodes.push_back(node_statement_t{{u8"edge_" + object_pointer_to_string(address_edge)},
                                {{
                                    {u8"id", u8"edge_" + object_pointer_to_string(address_edge)},
                                    {u8"style", u8"filled"},
                                    {u8"fillcolor", active_cell_color},
                                    {u8"label", html_label_t{fonttable_t{table_t{
                                                    .BORDER = 0,
                                                    .CELLBORDER = 1,
                                                    .CELLSPACING = 0,
                                                    .COLOR = std::get<part_index>(std::make_tuple(u8"#00000060", u8"#0000FF60", u8"#00B4B460")),
                                                    .rows = [&]()
                                                    {
                                                        decltype(table_t::rows) result;
                                                        if constexpr(generating_title)
                                                            result.push_back(row_t{{
                                                                cell_t{
                                                                    .COLOR = u8"transparent",
                                                                    .content = html_label_t{pointer_title_text_to_title_only(u8"edge", object_pointer_to_string(address_edge))},
                                                                },
                                                            }});
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .content = to_graphs_parameters.edge_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"edge",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        iterator_edge,
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                    .accumulated_storage_node_type =
#endif
                                                                        storage_node_type_e::top_tree_graph_edge,
                                                                }),
                                                            },
                                                        }});
                                                        return result; //
                                                    }(),
                                                }}}},
                                }}});
                            push_back_iterators_edge_nodes_and_edges(iterator_edge);
                        }

                        graph_t g{
                            .is_strict = false,
                            .is_directed = true,
                            .name = std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "augmented_graph").str().data())),
                            .statements = {
                                attr_t{u8"layout", u8"neato"},

                                attr_t{u8"label", u8""},
                                attr_t{u8"id", u8"graph"},

                                attr_t{u8"compound", u8"true"},
                                attr_t{u8"rankdir", u8"TB"},
                                attr_t{u8"outputorder", u8"nodesfirst"},
                                attr_t{u8"fontname", u8"Consolas"},
                                attr_t{u8"bgcolor", u8"transparent"},
                                attr_t{u8"labeljust", u8"c"},
                                attr_t{u8"labelloc", u8"t"},
                                attr_t{u8"forcelabels", u8"true"},
                                attr_t{u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                attr_t{u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                attr_statement_t{graph, {{
                                                            {u8"compound", u8"true"},
                                                            {u8"rankdir", u8"TB"},
                                                            {u8"outputorder", u8"nodesfirst"},
                                                            {u8"fontname", u8"Consolas"},
                                                            {u8"bgcolor", u8"transparent"},
                                                            {u8"labeljust", u8"c"},
                                                            {u8"labelloc", u8"t"},
                                                            {u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                            {u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                        }}},
                                attr_statement_t{node, {{
                                                           {u8"shape", u8"plain"},
                                                           {u8"width", u8"0"},
                                                           {u8"height", u8"0"},
                                                           {u8"margin", u8"0,0"},
                                                           {u8"fontname", u8"Consolas"},
                                                           {u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                           {u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                       }}},
                                attr_statement_t{edge, {{
                                                            {u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                            {u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                        }}},
                            },
                        };

                        for(typename part_t::cluster_list_node_navigator_t *p_list_node_navigator = part_t::cluster_list_node_navigator_t::untagged_next_or_tagged_end(part.cluster_list_node_end); p_list_node_navigator != part.cluster_list_node_end; p_list_node_navigator = p_list_node_navigator->next)
                        {
                            auto p_list_node = static_cast<typename part_t::cluster_list_node_t *>(p_list_node_navigator);

                            using cluster_tree_node_t = typename part_t::cluster_tree_node_t;

                            std::function<void(cluster_tree_node_t *, std::optional<typename container_t::it_vertex_t>, std::optional<typename container_t::it_vertex_t>, std::optional<typename container_t::it_vertex_t>)> tree_node_recursive = [&](cluster_tree_node_t *p_tree_node, std::optional<typename container_t::it_vertex_t>iterator_vertex_root, std::optional<typename container_t::it_vertex_t>iterator_vertex_from_excluded, std::optional<typename container_t::it_vertex_t>iterator_vertex_to_excluded)->void
                            {
                                typename part_t::cluster_t*address_cluster;
                                if constexpr(!std::is_same_v<typename part_t::cluster_t,void>)
                                    address_cluster = p_tree_node->p_cluster();
                                else
                                    address_cluster = p_tree_node;

                                auto add_vertex_if_not_added_before = [&](typename container_t::it_vertex_t iterator_vertex)
                                {
                                    if((!iterator_vertex_from_excluded.has_value()||iterator_vertex_from_excluded.value()!=iterator_vertex)&&
                                            (!iterator_vertex_to_excluded.has_value()||iterator_vertex_to_excluded.value()!=iterator_vertex))
                                    {
                                        push_back_vertex_node(iterator_vertex);
                                        push_back_iterators_vertex_nodes_and_edges(iterator_vertex);
                                    }
                                };
                                auto add_edge = [&](typename container_t::it_vertex_t iterator_vertex1, typename container_t::it_vertex_t iterator_vertex2)
                                {
                                    vertex_t const *address_vertex1 = &*iterator_vertex1;
                                    vertex_t const *address_vertex2 = &*iterator_vertex2;
                                    it_edge_it_vertexes_t iterator_edge = part.it_vertexes_it_vertexes_arc_and_it_edge_it_vertexes_base_level.at(iterator_vertex1).at(iterator_vertex2).second;
                                    edge_t const *address_edge = &iterator_edge->first;

                                    vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                     node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex1)},
                                                                                     node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                                 }},
                                        {{
                                            {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex1) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge"},
                                            {u8"headclip", u8"false"},
                                            {u8"dir", u8"back"},
                                            {u8"arrowsize", u8"0.0002"},
                                            {u8"penwidth", u8"3"},
                                        }}});
                                    vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                      node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex2)},
                                                                                     node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                                 }},
                                        {{
                                            {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex2) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge"},
                                            {u8"headclip", u8"false"},
                                            {u8"dir", u8"back"},
                                            {u8"arrowsize", u8"1"},
                                            {u8"penwidth", u8"3"},
                                        }}});

                                    edge_nodes.push_back(node_statement_t{{u8"edge_" + object_pointer_to_string(address_edge)},
                                        {{
                                            {u8"id", u8"edge_" + object_pointer_to_string(address_edge)},
                                            {u8"style", u8"filled"},
                                            {u8"fillcolor", active_cell_color},
                                            {u8"label", html_label_t{fonttable_t{table_t{
                                                            .BORDER = 0,
                                                            .CELLBORDER = 1,
                                                            .CELLSPACING = 0,
                                                            .COLOR = std::get<part_index>(std::make_tuple(u8"#00000060", u8"#0000FF60", u8"#00B4B460")),
                                                            .rows = [&]()
                                                            {
                                                                decltype(table_t::rows) result;
                                                                if constexpr(generating_title)
                                                                    result.push_back(row_t{{
                                                                        cell_t{
                                                                            .COLOR = u8"transparent",
                                                                            .content = html_label_t{pointer_title_text_to_title_only(u8"edge", object_pointer_to_string(address_edge))},
                                                                        },
                                                                    }});
                                                                result.push_back(row_t{{
                                                                    cell_t{
                                                                        .content = to_graphs_parameters.edge_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                            .member_name =
#endif
                                                                                u8"edge",
#ifndef __EMSCRIPTEN__
                                                                            .datum =
#endif
                                                                                iterator_edge,
#ifndef __EMSCRIPTEN__
                                                                            .converter_generated_statements_back_inserter =
#endif
                                                                                std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                            .accumulated_storage_node_type =
#endif
                                                                                storage_node_type_e::top_tree_graph_edge,
                                                                        }),
                                                                    },
                                                                }});
                                                                return result; //
                                                            }(),
                                                        }}}},
                                        }}});
                                    push_back_iterators_edge_nodes_and_edges(iterator_edge);
                                };

                                if(p_tree_node->child_left()==nullptr&&p_tree_node->child_right()==nullptr)// leaf
                                {
                                    add_vertex_if_not_added_before(p_tree_node->arc_backward.head);
                                    add_vertex_if_not_added_before(p_tree_node->arc_forward.head);
                                    if(!iterator_vertex_root.has_value())
                                    {
                                        assert(!iterator_vertex_from_excluded.has_value());
                                        assert(!iterator_vertex_to_excluded.has_value());
                                        add_edge(p_tree_node->arc_backward.head, p_tree_node->arc_forward.head);
                                    }
                                    else
                                    {
                                        if(iterator_vertex_root.value()==p_tree_node->arc_backward.head)
                                            add_edge(p_tree_node->arc_backward.head, p_tree_node->arc_forward.head);
                                        else if(iterator_vertex_root.value()==p_tree_node->arc_forward.head)
                                            add_edge(p_tree_node->arc_forward.head, p_tree_node->arc_backward.head);
                                        else std::unreachable();
                                    }
                                }
                                else if(p_tree_node->child_left()!=nullptr&&p_tree_node->child_right()==nullptr)// dummy
                                {
                                    tree_node_recursive(p_tree_node->child_left(), iterator_vertex_root, iterator_vertex_from_excluded, iterator_vertex_to_excluded);
                                }
                                else if(p_tree_node->child_left()!=nullptr&&p_tree_node->child_right()!=nullptr)
                                {
                                    if(!p_tree_node->contraction_type())// rake
                                    {
                                        auto[iterator_vertex_rake_from, iterator_vertex_rake_center, iterator_vertex_rake_to]=p_tree_node->rake_it_vertexes();
                                        if(!iterator_vertex_root.has_value())
                                        {
                                            assert(!iterator_vertex_from_excluded.has_value());
                                            assert(!iterator_vertex_to_excluded.has_value());
                                            tree_node_recursive(p_tree_node->child_left(), iterator_vertex_rake_center, iterator_vertex_rake_center, std::nullopt);
                                            tree_node_recursive(p_tree_node->child_right(), iterator_vertex_rake_center, std::nullopt, std::nullopt);
                                        }
                                        else
                                        {
                                            if(iterator_vertex_root.value()==iterator_vertex_rake_center)
                                            {
                                                assert(!iterator_vertex_from_excluded.has_value()||iterator_vertex_from_excluded.value()==iterator_vertex_rake_center);
                                                tree_node_recursive(p_tree_node->child_left(), iterator_vertex_rake_center, iterator_vertex_rake_center, std::nullopt);
                                                tree_node_recursive(p_tree_node->child_right(), iterator_vertex_rake_center, iterator_vertex_from_excluded, iterator_vertex_to_excluded);
                                            }
                                            else if(iterator_vertex_root.value()==iterator_vertex_rake_to)
                                            {
                                                assert(!iterator_vertex_to_excluded.has_value()||iterator_vertex_to_excluded.value()==iterator_vertex_rake_center);
                                                tree_node_recursive(p_tree_node->child_left(), iterator_vertex_rake_center, iterator_vertex_rake_center, std::nullopt);
                                                tree_node_recursive(p_tree_node->child_right(), iterator_vertex_rake_to, iterator_vertex_from_excluded, iterator_vertex_to_excluded);
                                            }
                                            else std::unreachable();
                                        }
                                    }
                                    else// compress
                                    {
                                        typename container_t::it_vertex_t iterator_vertex_compress_vertex1 = p_tree_node->arc_backward.head, iterator_vertex_compress_center, iterator_vertex_compress_vertex2 = p_tree_node->arc_forward.head;
                                        if(p_tree_node->child_left()->arc_backward.head == p_tree_node->arc_backward.head)
                                            iterator_vertex_compress_center = p_tree_node->child_left()->arc_forward.head;
                                        else if(p_tree_node->child_left()->arc_forward.head == p_tree_node->arc_backward.head)
                                            iterator_vertex_compress_center = p_tree_node->child_left()->arc_backward.head;
                                        else std::unreachable();
                                        add_vertex_if_not_added_before(iterator_vertex_compress_center);
                                        if(!iterator_vertex_root.has_value())
                                        {
                                            assert(!iterator_vertex_from_excluded.has_value());
                                            assert(!iterator_vertex_to_excluded.has_value());
                                            tree_node_recursive(p_tree_node->child_left(), iterator_vertex_compress_center, iterator_vertex_compress_center, std::nullopt);
                                            tree_node_recursive(p_tree_node->child_right(), iterator_vertex_compress_center, iterator_vertex_compress_center, std::nullopt);
                                        }
                                        else
                                        {
                                            if(iterator_vertex_root.value()==iterator_vertex_compress_vertex1)
                                            {
                                                tree_node_recursive(p_tree_node->child_left(), iterator_vertex_compress_vertex1, iterator_vertex_from_excluded, iterator_vertex_compress_center);
                                                tree_node_recursive(p_tree_node->child_right(), iterator_vertex_compress_center, iterator_vertex_compress_center, iterator_vertex_to_excluded);
                                            }
                                            else if(iterator_vertex_root.value()==iterator_vertex_compress_vertex2)
                                            {
                                                tree_node_recursive(p_tree_node->child_left(), iterator_vertex_compress_center, iterator_vertex_compress_center, iterator_vertex_to_excluded);
                                                tree_node_recursive(p_tree_node->child_right(), iterator_vertex_compress_vertex2, iterator_vertex_from_excluded, iterator_vertex_compress_center);
                                            }
                                            else std::unreachable();
                                        }
                                    }
                                }
                            };

                            tree_node_recursive(p_list_node->tree_root, std::nullopt, std::nullopt, std::nullopt);
                        }

                        std::ranges::copy(vertex_nodes, std::back_inserter(g.statements));
                        std::ranges::copy(edge_nodes, std::back_inserter(g.statements));
                        std::ranges::copy(vertex_edge_edges, std::back_inserter(g.statements));
                        std::ranges::copy(iterator_vertex_nodes, std::back_inserter(g.statements));
                        std::ranges::copy(iterator_vertex_edges, std::back_inserter(g.statements));
                        std::ranges::copy(iterator_edge_nodes, std::back_inserter(g.statements));
                        std::ranges::copy(iterator_edge_edges, std::back_inserter(g.statements));

                        std::ranges::copy(converter_generated_statements, std::back_inserter(g.statements));

                        sub_result.push_back(g);
                    }

                    {
                        std::vector<std::variant<node_statement_t, edge_statement_t, attr_statement_t, attr_t, subgraph_t>> converter_generated_statements;

                        std::vector<node_statement_t> vertex_nodes;
                        std::vector<node_statement_t> edge_nodes;
                        std::vector<edge_statement_t> vertex_edge_edges;
                        std::vector<node_statement_t> iterator_vertex_nodes;
                        std::vector<edge_statement_t> iterator_vertex_edges;
                        std::vector<node_statement_t> iterator_edge_nodes;
                        std::vector<edge_statement_t> iterator_edge_edges;

                        using it_vertex_t=typename container_t::it_vertex_t;
                        using it_edge_it_vertexes_t=typename container_t::it_edge_it_vertexes_t;

                        auto push_back_vertex_node=[&](auto&container_nodes, it_vertex_t iterator_vertex)
                        {
                            vertex_t const *address_vertex = &*iterator_vertex;
                            container_nodes.push_back(node_statement_t{{u8"vertex_" + object_pointer_to_string(address_vertex)},
                                {{
                                    {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex)},
                                    {u8"shape", u8"ellipse"},
                                    {u8"margin", u8"0.05,0.05"},
                                    {u8"style", u8"filled"},
                                    {u8"fillcolor", active_cell_color},
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
                                                                    .content = html_label_t{pointer_title_text_to_title_only(u8"vertex", object_pointer_to_string(address_vertex))},
                                                                },
                                                            }});
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .BORDER=part.it_vertex_exposed1==iterator_vertex||part.it_vertex_exposed2==iterator_vertex?std::make_optional<double>(2):std::nullopt,
                                                                .COLOR=part.it_vertex_exposed1==iterator_vertex||part.it_vertex_exposed2==iterator_vertex?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"vertex",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        iterator_vertex,
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                    .accumulated_storage_node_type =
#endif
                                                                        storage_node_type_e::top_tree_graph_hierarchy_vertex,
                                                                }),
                                                            },
                                                        }});
                                                        return result; //
                                                    }(),
                                                }}}},
                                }}});
                        };
                        auto push_back_iterators_vertex_nodes_and_edges=[&](auto&container_nodes, auto&container_edges, it_vertex_t current_iterator_vertex)
                        {
                            std::ranges::for_each(to_graphs_parameters.iterators_vertex, [&, index = 0](auto iterator_vertex) mutable
                                {
                                    if(iterator_vertex == current_iterator_vertex)
                                    {
                                        vertex_t const *address_vertex = &*iterator_vertex;
                                        container_nodes.push_back(node_statement_t{{u8"itv[" + index_to_string(index) + u8"]"},
                                            {{
                                                {u8"id", u8"itv[" + index_to_string(index) + u8"]"},
                                                {u8"label", u8"itv[" + index_to_string(index) + u8"]"},
                                            }}});
                                        container_edges.push_back(edge_statement_t{{{
                                                                                        node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex)},
                                                                                        node_id_t{u8"itv[" + index_to_string(index) + u8"]"},
                                                                                    }},
                                            {{
                                                {u8"id", u8"itv[" + index_to_string(index) + u8"]" + u8"->vertex"},
                                                {u8"dir", u8"back"},
                                            }}});
                                    }
                                    ++index; //
                                });
                        };
                        auto push_back_iterators_edge_nodes_and_edges=[&](auto&container_nodes, auto&container_edges, it_edge_it_vertexes_t current_iterator_edge)
                        {
                            std::ranges::for_each(to_graphs_parameters.iterators_edge, [&, index = 0](auto iterator_edge) mutable
                                {
                                    if(iterator_edge == current_iterator_edge)
                                    {
                                        edge_t const *address_edge = &iterator_edge->first;
                                        container_nodes.push_back(node_statement_t{{u8"ite[" + index_to_string(index) + u8"]"},
                                            {{
                                                {u8"id", u8"ite[" + index_to_string(index) + u8"]"},
                                                {u8"label", u8"ite[" + index_to_string(index) + u8"]"},
                                            }}});
                                        container_edges.push_back(edge_statement_t{{{
                                                                                        node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                                        node_id_t{u8"ite[" + index_to_string(index) + u8"]"},
                                                                                    }},
                                            {{
                                                {u8"id", u8"ite[" + index_to_string(index) + u8"]" + u8"->edge"},
                                                {u8"dir", u8"back"},
                                            }}});
                                    }
                                    ++index; //
                                });
                        };

                        for(it_vertex_t iterator_vertex : part.it_vertexes_trivial_component)
                        {
                            push_back_vertex_node(vertex_nodes, iterator_vertex);
                            push_back_iterators_vertex_nodes_and_edges(iterator_vertex_nodes, iterator_vertex_edges, iterator_vertex);
                        }
                        for(it_edge_it_vertexes_t iterator_edge:part.it_edges_fundamental)
                        {
                            vertex_t const *address_vertex1 = &*iterator_edge->second.first;
                            vertex_t const *address_vertex2 = &*iterator_edge->second.second;
                            edge_t const *address_edge = &iterator_edge->first;

                            if(iterator_edge->second.first==iterator_edge->second.second)
                            {
                                vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                 node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex1)},
                                                                                 node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                             }},
                                    {{
                                        {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex1) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge1"},
                                        {u8"headclip", u8"false"},
                                        {u8"dir", u8"none"},
                                    }}});
                                vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                  node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex2)},
                                                                                  node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                             }},
                                    {{
                                        {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex2) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge2"},
                                        {u8"headclip", u8"false"},
                                        {u8"dir", u8"none"},
                                    }}});
                            }
                            else
                            {
                                vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                 node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex1)},
                                                                                 node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                             }},
                                    {{
                                        {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex1) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge"},
                                        {u8"headclip", u8"false"},
                                        {u8"dir", u8"none"},
                                    }}});
                                vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                  node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex2)},
                                                                                  node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                             }},
                                    {{
                                        {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex2) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge"},
                                        {u8"headclip", u8"false"},
                                        {u8"dir", u8"none"},
                                    }}});
                            }
                            edge_nodes.push_back(node_statement_t{{u8"edge_" + object_pointer_to_string(address_edge)},
                                {{
                                    {u8"id", u8"edge_" + object_pointer_to_string(address_edge)},
                                    {u8"style", u8"filled"},
                                    {u8"fillcolor", active_cell_color},
                                    {u8"label", html_label_t{fonttable_t{table_t{
                                                    .BORDER = 0,
                                                    .CELLBORDER = 1,
                                                    .CELLSPACING = 0,
                                                    .COLOR = std::get<part_index>(std::make_tuple(u8"#00000060", u8"#0000FF60", u8"#00B4B460")),
                                                    .rows = [&]()
                                                    {
                                                        decltype(table_t::rows) result;
                                                        if constexpr(generating_title)
                                                            result.push_back(row_t{{
                                                                cell_t{
                                                                    .COLOR = u8"transparent",
                                                                    .content = html_label_t{pointer_title_text_to_title_only(u8"edge", object_pointer_to_string(address_edge))},
                                                                },
                                                            }});
                                                        result.push_back(row_t{{
                                                            cell_t{
                                                                .content = to_graphs_parameters.edge_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"edge",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        iterator_edge,
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                    .accumulated_storage_node_type =
#endif
                                                                        storage_node_type_e::top_tree_graph_hierarchy_edge,
                                                                }),
                                                            },
                                                        }});
                                                        return result; //
                                                    }(),
                                                }}}},
                                }}});
                            push_back_iterators_edge_nodes_and_edges(iterator_edge_nodes, iterator_edge_edges, iterator_edge);
                        }

                        graph_t g{
                            .is_strict = false,
                            .is_directed = true,
                            .name = std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "augmented_graph").str().data())),
                            .statements = {
                                attr_t{u8"label", u8""},
                                attr_t{u8"id", u8"graph"},

                                attr_t{u8"compound", u8"true"},
                                attr_t{u8"rankdir", u8"TB"},
                                attr_t{u8"outputorder", u8"nodesfirst"},
                                attr_t{u8"fontname", u8"Consolas"},
                                attr_t{u8"bgcolor", u8"transparent"},
                                attr_t{u8"labeljust", u8"c"},
                                attr_t{u8"labelloc", u8"t"},
                                attr_t{u8"forcelabels", u8"true"},
                                attr_t{u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                attr_t{u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                attr_statement_t{graph, {{
                                                            {u8"compound", u8"true"},
                                                            {u8"rankdir", u8"TB"},
                                                            {u8"outputorder", u8"nodesfirst"},
                                                            {u8"fontname", u8"Consolas"},
                                                            {u8"bgcolor", u8"transparent"},
                                                            {u8"labeljust", u8"c"},
                                                            {u8"labelloc", u8"t"},
                                                            {u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                            {u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                        }}},
                                attr_statement_t{node, {{
                                                           {u8"shape", u8"plain"},
                                                           {u8"width", u8"0"},
                                                           {u8"height", u8"0"},
                                                           {u8"margin", u8"0,0"},
                                                           {u8"fontname", u8"Consolas"},
                                                           {u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                           {u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                       }}},
                                attr_statement_t{edge, {{
                                                            {u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                            {u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                        }}},
                            },
                        };

                        for(typename part_t::cluster_list_node_navigator_t *p_list_node_navigator = part_t::cluster_list_node_navigator_t::untagged_next_or_tagged_end(part.cluster_list_node_end); p_list_node_navigator != part.cluster_list_node_end; p_list_node_navigator = p_list_node_navigator->next)
                        {
                            auto p_list_node = static_cast<typename part_t::cluster_list_node_t *>(p_list_node_navigator);

                            using cluster_tree_node_t = typename part_t::cluster_tree_node_t;

                            std::function<subgraph_t(cluster_tree_node_t *, std::optional<typename container_t::it_vertex_t>, std::optional<typename container_t::it_vertex_t>, std::optional<typename container_t::it_vertex_t>)> tree_node_recursive = [&](cluster_tree_node_t *p_tree_node, std::optional<typename container_t::it_vertex_t>iterator_vertex_root, std::optional<typename container_t::it_vertex_t>iterator_vertex_from_excluded, std::optional<typename container_t::it_vertex_t>iterator_vertex_to_excluded)->subgraph_t
                            {
                                typename part_t::cluster_t*address_cluster;
                                if constexpr(!std::is_same_v<typename part_t::cluster_t,void>)
                                    address_cluster = p_tree_node->p_cluster();
                                else
                                    address_cluster = p_tree_node;

                                subgraph_t cluster_cluster{
                                    .name = u8"cluster_" + object_pointer_to_string(address_cluster) + u8"_cluster",
                                    .statements = {
                                        attr_t{u8"id", u8"cluster_" + object_pointer_to_string(address_cluster) + u8"_cluster"},

                                        attr_t{u8"cluster", u8"true"},
                                        attr_t{u8"label", html_label_t{fonttable_t{table_t{
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
                                                            .COLSPAN = [&]()->int{
                                                                if(p_tree_node->child_left()==nullptr&&p_tree_node->child_right()==nullptr)// leaf
                                                                    return 2;
                                                                else if(p_tree_node->child_left()!=nullptr&&p_tree_node->child_right()==nullptr)// dummy
                                                                    return 5;
                                                                else if(p_tree_node->child_left()!=nullptr&&p_tree_node->child_right()!=nullptr)// rake or compress
                                                                    return 8;
                                                           },
                                                            .content = html_label_t{pointer_title_text_to_title_only(u8"cluster", object_pointer_to_string(address_cluster))},
                                                        },
                                                    }});
                                                result.push_back(
                                                    row_t{[&](){
                                                        decltype(row_t::cells) cells;
                                                        cells.push_back(cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .BORDER=part.it_vertex_exposed1==p_tree_node->arc_backward.head||part.it_vertex_exposed2==p_tree_node->arc_backward.head?std::make_optional<double>(2):std::nullopt,
                                                            .COLOR=part.it_vertex_exposed1==p_tree_node->arc_backward.head||part.it_vertex_exposed2==p_tree_node->arc_backward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                            .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .member_name =
#endif
                                                                    u8"cluster_title.vertex1",
#ifndef __EMSCRIPTEN__
                                                                .datum =
#endif
                                                                    p_tree_node->arc_backward.head,
#ifndef __EMSCRIPTEN__
                                                                .converter_generated_statements_back_inserter =
#endif
                                                                    std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                .accumulated_storage_node_type =
#endif
                                                                    storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                            }),
                                                        });
                                                        cells.push_back(cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .BORDER=part.it_vertex_exposed1==p_tree_node->arc_forward.head||part.it_vertex_exposed2==p_tree_node->arc_forward.head?std::make_optional<double>(2):std::nullopt,
                                                            .COLOR=part.it_vertex_exposed1==p_tree_node->arc_forward.head||part.it_vertex_exposed2==p_tree_node->arc_forward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                            .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .member_name =
#endif
                                                                    u8"cluster_title.vertex2",
#ifndef __EMSCRIPTEN__
                                                                .datum =
#endif
                                                                    p_tree_node->arc_forward.head,
#ifndef __EMSCRIPTEN__
                                                                .converter_generated_statements_back_inserter =
#endif
                                                                    std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                .accumulated_storage_node_type =
#endif
                                                                    storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                            }),
                                                        });
                                                        if(p_tree_node->child_left()==nullptr&&p_tree_node->child_right()==nullptr)// leaf
                                                            ;
                                                        else if(p_tree_node->child_left()!=nullptr&&p_tree_node->child_right()==nullptr)// dummy
                                                        {
                                                            cells.push_back(cell_t{
                                                                .BORDER = 0, /* .COLOR = u8"transparent", */
                                                                .ROWSPAN = !std::is_same_v<typename part_t::cluster_t,void> ? 2 : 1,
                                                                .content=[&]()
                                                                { return html_label_t{text_t{{{u8"＝"}}}}; }(),
                                                            });
                                                            cells.push_back(cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .BORDER=part.it_vertex_exposed1==p_tree_node->child_left()->arc_backward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_backward.head?std::make_optional<double>(2):std::nullopt,
                                                                .COLOR=part.it_vertex_exposed1==p_tree_node->child_left()->arc_backward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_backward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"cluster_title.child_left.vertex1",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        p_tree_node->child_left()->arc_backward.head,
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                    .accumulated_storage_node_type =
#endif
                                                                        storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                                }),
                                                            });
                                                            cells.push_back(cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .BORDER=part.it_vertex_exposed1==p_tree_node->child_left()->arc_forward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_forward.head?std::make_optional<double>(2):std::nullopt,
                                                                .COLOR=part.it_vertex_exposed1==p_tree_node->child_left()->arc_forward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_forward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"cluster_title.child_left.vertex2",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        p_tree_node->child_left()->arc_forward.head,
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                    .accumulated_storage_node_type =
#endif
                                                                        storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                                }),
                                                            });
                                                        }
                                                        else if(p_tree_node->child_left()!=nullptr&&p_tree_node->child_right()!=nullptr)
                                                        {
                                                            if(!p_tree_node->contraction_type())// rake
                                                            {
                                                                cells.push_back(cell_t{
                                                                    .BORDER = 0, /* .COLOR = u8"transparent", */
                                                                    .ROWSPAN = !std::is_same_v<typename part_t::cluster_t,void> ? 2 : 1,
                                                                    .content=[&](){ return html_label_t{text_t{{{u8"＝"}}}}; }(),
                                                                });
                                                                cells.push_back(cell_t{
                                                                    .BGCOLOR = active_cell_color,
                                                                    .BORDER=part.it_vertex_exposed1==p_tree_node->child_left()->arc_backward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_backward.head?std::make_optional<double>(2):std::nullopt,
                                                                    .COLOR=part.it_vertex_exposed1==p_tree_node->child_left()->arc_backward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_backward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                    .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                        .member_name =
#endif
                                                                            u8"cluster_title.child_left.vertex1",
#ifndef __EMSCRIPTEN__
                                                                        .datum =
#endif
                                                                            p_tree_node->child_left()->arc_backward.head,
#ifndef __EMSCRIPTEN__
                                                                        .converter_generated_statements_back_inserter =
#endif
                                                                            std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                        .accumulated_storage_node_type =
#endif
                                                                            storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                                    }),
                                                                });
                                                                cells.push_back(cell_t{
                                                                    .BGCOLOR = active_cell_color,
                                                                    .BORDER=part.it_vertex_exposed1==p_tree_node->child_left()->arc_forward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_forward.head?std::make_optional<double>(2):std::nullopt,
                                                                    .COLOR=part.it_vertex_exposed1==p_tree_node->child_left()->arc_forward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_forward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                    .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                        .member_name =
#endif
                                                                            u8"cluster_title.child_left.vertex2",
#ifndef __EMSCRIPTEN__
                                                                        .datum =
#endif
                                                                            p_tree_node->child_left()->arc_forward.head,
#ifndef __EMSCRIPTEN__
                                                                        .converter_generated_statements_back_inserter =
#endif
                                                                            std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                        .accumulated_storage_node_type =
#endif
                                                                            storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                                    }),
                                                                });
                                                                cells.push_back(cell_t{
                                                                    .BORDER = 0, /* .COLOR = u8"transparent", */
                                                                    .ROWSPAN = !std::is_same_v<typename part_t::cluster_t,void> ? 2 : 1,
                                                                    .content=html_label_t{[](){return text_t{{textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF", .FACE = u8"Cambria Math"}, text_t{{{u8"⤻"}}})}}};}()},
                                                                });
                                                                cells.push_back(cell_t{
                                                                    .BGCOLOR = active_cell_color,
                                                                    .BORDER=part.it_vertex_exposed1==p_tree_node->child_right()->arc_backward.head||part.it_vertex_exposed2==p_tree_node->child_right()->arc_backward.head?std::make_optional<double>(2):std::nullopt,
                                                                    .COLOR=part.it_vertex_exposed1==p_tree_node->child_right()->arc_backward.head||part.it_vertex_exposed2==p_tree_node->child_right()->arc_backward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                    .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                        .member_name =
#endif
                                                                            u8"cluster_title.child_right.vertex1",
#ifndef __EMSCRIPTEN__
                                                                        .datum =
#endif
                                                                            p_tree_node->child_right()->arc_backward.head,
#ifndef __EMSCRIPTEN__
                                                                        .converter_generated_statements_back_inserter =
#endif
                                                                            std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                        .accumulated_storage_node_type =
#endif
                                                                            storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                                    }),
                                                                });
                                                                cells.push_back(cell_t{
                                                                    .BGCOLOR = active_cell_color,
                                                                    .BORDER=part.it_vertex_exposed1==p_tree_node->child_right()->arc_forward.head||part.it_vertex_exposed2==p_tree_node->child_right()->arc_forward.head?std::make_optional<double>(2):std::nullopt,
                                                                    .COLOR=part.it_vertex_exposed1==p_tree_node->child_right()->arc_forward.head||part.it_vertex_exposed2==p_tree_node->child_right()->arc_forward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                    .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                        .member_name =
#endif
                                                                            u8"cluster_title.child_right.vertex2",
#ifndef __EMSCRIPTEN__
                                                                        .datum =
#endif
                                                                            p_tree_node->child_right()->arc_forward.head,
#ifndef __EMSCRIPTEN__
                                                                        .converter_generated_statements_back_inserter =
#endif
                                                                            std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                        .accumulated_storage_node_type =
#endif
                                                                            storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                                    }),
                                                                });
                                                            }
                                                            else// compress
                                                            {
                                                                cells.push_back(cell_t{
                                                                    .BORDER = 0, /* .COLOR = u8"transparent", */
                                                                    .ROWSPAN = !std::is_same_v<typename part_t::cluster_t,void> ? 2 : 1,
                                                                    .content=[&](){ return html_label_t{text_t{{{u8"＝"}}}}; }(),
                                                                });
                                                                cells.push_back(cell_t{
                                                                    .BGCOLOR = active_cell_color,
                                                                    .BORDER=part.it_vertex_exposed1==p_tree_node->child_left()->arc_backward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_backward.head?std::make_optional<double>(2):std::nullopt,
                                                                    .COLOR=part.it_vertex_exposed1==p_tree_node->child_left()->arc_backward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_backward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                    .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                        .member_name =
#endif
                                                                            u8"cluster_title.child_left.vertex1",
#ifndef __EMSCRIPTEN__
                                                                        .datum =
#endif
                                                                            p_tree_node->child_left()->arc_backward.head,
#ifndef __EMSCRIPTEN__
                                                                        .converter_generated_statements_back_inserter =
#endif
                                                                            std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                        .accumulated_storage_node_type =
#endif
                                                                            storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                                    }),
                                                                });
                                                                cells.push_back(cell_t{
                                                                    .BGCOLOR = active_cell_color,
                                                                    .BORDER=part.it_vertex_exposed1==p_tree_node->child_left()->arc_forward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_forward.head?std::make_optional<double>(2):std::nullopt,
                                                                    .COLOR=part.it_vertex_exposed1==p_tree_node->child_left()->arc_forward.head||part.it_vertex_exposed2==p_tree_node->child_left()->arc_forward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                    .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                        .member_name =
#endif
                                                                            u8"cluster_title.child_left.vertex2",
#ifndef __EMSCRIPTEN__
                                                                        .datum =
#endif
                                                                            p_tree_node->child_left()->arc_forward.head,
#ifndef __EMSCRIPTEN__
                                                                        .converter_generated_statements_back_inserter =
#endif
                                                                            std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                        .accumulated_storage_node_type =
#endif
                                                                            storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                                    }),
                                                                });
                                                                cells.push_back(cell_t{
                                                                    .BORDER = 0, /* .COLOR = u8"transparent", */
                                                                    .ROWSPAN = !std::is_same_v<typename part_t::cluster_t,void> ? 2 : 1,
                                                                    .content=html_label_t{[](){return text_t{{textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF", .FACE = u8"Cambria Math"}, text_t{{{u8"→←"}}})}}};}()},
                                                                });
                                                                cells.push_back(cell_t{
                                                                    .BGCOLOR = active_cell_color,
                                                                    .BORDER=part.it_vertex_exposed1==p_tree_node->child_right()->arc_backward.head||part.it_vertex_exposed2==p_tree_node->child_right()->arc_backward.head?std::make_optional<double>(2):std::nullopt,
                                                                    .COLOR=part.it_vertex_exposed1==p_tree_node->child_right()->arc_backward.head||part.it_vertex_exposed2==p_tree_node->child_right()->arc_backward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                    .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                        .member_name =
#endif
                                                                            u8"cluster_title.child_right.vertex1",
#ifndef __EMSCRIPTEN__
                                                                        .datum =
#endif
                                                                            p_tree_node->child_right()->arc_backward.head,
#ifndef __EMSCRIPTEN__
                                                                        .converter_generated_statements_back_inserter =
#endif
                                                                            std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                        .accumulated_storage_node_type =
#endif
                                                                            storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                                    }),
                                                                });
                                                                cells.push_back(cell_t{
                                                                    .BGCOLOR = active_cell_color,
                                                                    .BORDER=part.it_vertex_exposed1==p_tree_node->child_right()->arc_forward.head||part.it_vertex_exposed2==p_tree_node->child_right()->arc_forward.head?std::make_optional<double>(2):std::nullopt,
                                                                    .COLOR=part.it_vertex_exposed1==p_tree_node->child_right()->arc_forward.head||part.it_vertex_exposed2==p_tree_node->child_right()->arc_forward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                    .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                        .member_name =
#endif
                                                                            u8"cluster_title.child_right.vertex2",
#ifndef __EMSCRIPTEN__
                                                                        .datum =
#endif
                                                                            p_tree_node->child_right()->arc_forward.head,
#ifndef __EMSCRIPTEN__
                                                                        .converter_generated_statements_back_inserter =
#endif
                                                                            std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                        .accumulated_storage_node_type =
#endif
                                                                            storage_node_type_e::top_tree_graph_hierarchy_cluster_title_vertex,
                                                                    }),
                                                                });
                                                            }
                                                        }
                                                        return cells;
                                                   }()});
                                                if constexpr(!std::is_same_v<typename part_t::cluster_t,void>)
                                                    result.push_back(row_t{[&](){
                                                        decltype(row_t::cells) cells;
                                                        cells.push_back(cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 2,
                                                            .content = std::get<part_index>(to_graphs_parameters.part_data_to_string_converter_per_part)(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .member_name =
#endif
                                                                    u8"cluster",
#ifndef __EMSCRIPTEN__
                                                                .datum =
#endif
                                                                    std::make_tuple(p_tree_node->arc_backward.head, std::cref(*p_tree_node->p_cluster()), p_tree_node->arc_forward.head),
#ifndef __EMSCRIPTEN__
                                                                .converter_generated_statements_back_inserter =
#endif
                                                                    std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                .accumulated_storage_node_type =
#endif
                                                                    storage_node_type_e::top_tree_graph_hierarchy_cluster_title_cluster,
                                                            }),
                                                        });
                                                        if(p_tree_node->child_left()==nullptr&&p_tree_node->child_right()==nullptr)// leaf
                                                            ;
                                                        else if(p_tree_node->child_left()!=nullptr&&p_tree_node->child_right()==nullptr)// dummy
                                                            cells.push_back(cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 2,
                                                                .content = std::get<part_index>(to_graphs_parameters.part_data_to_string_converter_per_part)(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"cluster",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        std::make_tuple(p_tree_node->child_left()->arc_backward.head, std::cref(*p_tree_node->child_left()->p_cluster()), p_tree_node->child_left()->arc_forward.head),
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                    .accumulated_storage_node_type =
#endif
                                                                        storage_node_type_e::top_tree_graph_hierarchy_cluster_title_cluster,
                                                                }),
                                                            });
                                                        else if(p_tree_node->child_left()!=nullptr&&p_tree_node->child_right()!=nullptr)
                                                        {
                                                            cells.push_back(cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 2,
                                                                .content = std::get<part_index>(to_graphs_parameters.part_data_to_string_converter_per_part)(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"cluster",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        std::make_tuple(p_tree_node->child_left()->arc_backward.head, std::cref(*p_tree_node->child_left()->p_cluster()), p_tree_node->child_left()->arc_forward.head),
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                    .accumulated_storage_node_type =
#endif
                                                                        storage_node_type_e::top_tree_graph_hierarchy_cluster_title_cluster,
                                                                }),
                                                            });
                                                            cells.push_back(cell_t{
                                                                .BGCOLOR = active_cell_color,
                                                                .COLSPAN = 2,
                                                                .content = std::get<part_index>(to_graphs_parameters.part_data_to_string_converter_per_part)(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                    .member_name =
#endif
                                                                        u8"cluster",
#ifndef __EMSCRIPTEN__
                                                                    .datum =
#endif
                                                                        std::make_tuple(p_tree_node->child_right()->arc_backward.head, std::cref(*p_tree_node->child_right()->p_cluster()), p_tree_node->child_right()->arc_forward.head),
#ifndef __EMSCRIPTEN__
                                                                    .converter_generated_statements_back_inserter =
#endif
                                                                        std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                    .accumulated_storage_node_type =
#endif
                                                                        storage_node_type_e::top_tree_graph_hierarchy_cluster_title_cluster,
                                                                }),
                                                            });
                                                        }
                                                        return cells;
                                                    }()});
                                                return result; //
                                            }(),
                                        }}}},
                                    },
                                };

                                auto add_vertex_if_not_added_before = [&](typename container_t::it_vertex_t iterator_vertex)
                                {
                                    if((!iterator_vertex_from_excluded.has_value()||iterator_vertex_from_excluded.value()!=iterator_vertex)&&
                                            (!iterator_vertex_to_excluded.has_value()||iterator_vertex_to_excluded.value()!=iterator_vertex))
                                    {
                                        push_back_vertex_node(cluster_cluster.statements, iterator_vertex);
                                        push_back_iterators_vertex_nodes_and_edges(cluster_cluster.statements, iterator_vertex_edges, iterator_vertex);
                                    }
                                };
                                auto add_edge = [&](typename container_t::it_vertex_t iterator_vertex1, typename container_t::it_vertex_t iterator_vertex2)
                                {
                                    vertex_t const *address_vertex1 = &*iterator_vertex1;
                                    vertex_t const *address_vertex2 = &*iterator_vertex2;
                                    it_edge_it_vertexes_t iterator_edge = part.it_vertexes_it_vertexes_arc_and_it_edge_it_vertexes_base_level.at(iterator_vertex1).at(iterator_vertex2).second;
                                    edge_t const *address_edge = &iterator_edge->first;

                                    vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                     node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex1)},
                                                                                     node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                                 }},
                                        {{
                                            {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex1) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge"},
                                            {u8"headclip", u8"false"},
                                            {u8"dir", u8"none"},
                                        }}});
                                    vertex_edge_edges.push_back(edge_statement_t{{{
                                                                                      node_id_t{u8"edge_" + object_pointer_to_string(address_edge)},
                                                                                     node_id_t{u8"vertex_" + object_pointer_to_string(address_vertex2)},
                                                                                 }},
                                        {{
                                            {u8"id", u8"vertex_" + object_pointer_to_string(address_vertex2) + u8"_edge_" + object_pointer_to_string(address_edge) + u8"_edge"},
                                            {u8"tailclip", u8"false"},
                                        }}});

                                    cluster_cluster.statements.push_back(node_statement_t{{u8"edge_" + object_pointer_to_string(address_edge)},
                                        {{
                                            {u8"id", u8"edge_" + object_pointer_to_string(address_edge)},
                                            {u8"style", u8"filled"},
                                            {u8"fillcolor", active_cell_color},
                                            {u8"label", html_label_t{fonttable_t{table_t{
                                                            .BORDER = 0,
                                                            .CELLBORDER = 1,
                                                            .CELLSPACING = 0,
                                                            .COLOR = std::get<part_index>(std::make_tuple(u8"#00000060", u8"#0000FF60", u8"#00B4B460")),
                                                            .rows = [&]()
                                                            {
                                                                decltype(table_t::rows) result;
                                                                if constexpr(generating_title)
                                                                    result.push_back(row_t{{
                                                                        cell_t{
                                                                            .COLOR = u8"transparent",
                                                                            .content = html_label_t{pointer_title_text_to_title_only(u8"edge", object_pointer_to_string(address_edge))},
                                                                        },
                                                                    }});
                                                                result.push_back(row_t{{
                                                                    cell_t{
                                                                        .content = to_graphs_parameters.edge_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                            .member_name =
#endif
                                                                                u8"edge",
#ifndef __EMSCRIPTEN__
                                                                            .datum =
#endif
                                                                                iterator_edge,
#ifndef __EMSCRIPTEN__
                                                                            .converter_generated_statements_back_inserter =
#endif
                                                                                std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                            .accumulated_storage_node_type =
#endif
                                                                                storage_node_type_e::top_tree_graph_hierarchy_edge,
                                                                        }),
                                                                    },
                                                                }});
                                                                return result; //
                                                            }(),
                                                        }}}},
                                        }}});
                                    push_back_iterators_edge_nodes_and_edges(cluster_cluster.statements, iterator_edge_edges, iterator_edge);
                                };

                                if(p_tree_node->child_left()==nullptr&&p_tree_node->child_right()==nullptr)// leaf
                                {
                                    add_vertex_if_not_added_before(p_tree_node->arc_backward.head);
                                    add_vertex_if_not_added_before(p_tree_node->arc_forward.head);
                                    if(!iterator_vertex_root.has_value())
                                    {
                                        assert(!iterator_vertex_from_excluded.has_value());
                                        assert(!iterator_vertex_to_excluded.has_value());
                                        add_edge(p_tree_node->arc_backward.head, p_tree_node->arc_forward.head);
                                    }
                                    else
                                    {
                                        if(iterator_vertex_root.value()==p_tree_node->arc_backward.head)
                                            add_edge(p_tree_node->arc_backward.head, p_tree_node->arc_forward.head);
                                        else if(iterator_vertex_root.value()==p_tree_node->arc_forward.head)
                                            add_edge(p_tree_node->arc_forward.head, p_tree_node->arc_backward.head);
                                        else std::unreachable();
                                    }
                                }
                                else if(p_tree_node->child_left()!=nullptr&&p_tree_node->child_right()==nullptr)// dummy
                                {
                                    cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_left(), iterator_vertex_root, iterator_vertex_from_excluded, iterator_vertex_to_excluded));
                                }
                                else if(p_tree_node->child_left()!=nullptr&&p_tree_node->child_right()!=nullptr)
                                {
                                    if(!p_tree_node->contraction_type())// rake
                                    {
                                        auto[iterator_vertex_rake_from, iterator_vertex_rake_center, iterator_vertex_rake_to]=p_tree_node->rake_it_vertexes();
                                        if(!iterator_vertex_root.has_value())
                                        {
                                            assert(!iterator_vertex_from_excluded.has_value());
                                            assert(!iterator_vertex_to_excluded.has_value());
                                            cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_left(), iterator_vertex_rake_center, iterator_vertex_rake_center, std::nullopt));
                                            cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_right(), iterator_vertex_rake_center, std::nullopt, std::nullopt));
                                        }
                                        else
                                        {
                                            if(iterator_vertex_root.value()==iterator_vertex_rake_center)
                                            {
                                                assert(!iterator_vertex_from_excluded.has_value()||iterator_vertex_from_excluded.value()==iterator_vertex_rake_center);
                                                cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_left(), iterator_vertex_rake_center, iterator_vertex_rake_center, std::nullopt));
                                                cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_right(), iterator_vertex_rake_center, iterator_vertex_from_excluded, iterator_vertex_to_excluded));
                                            }
                                            else if(iterator_vertex_root.value()==iterator_vertex_rake_to)
                                            {
                                                assert(!iterator_vertex_to_excluded.has_value()||iterator_vertex_to_excluded.value()==iterator_vertex_rake_center);
                                                cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_left(), iterator_vertex_rake_center, iterator_vertex_rake_center, std::nullopt));
                                                cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_right(), iterator_vertex_rake_to, iterator_vertex_from_excluded, iterator_vertex_to_excluded));
                                            }
                                            else std::unreachable();
                                        }
                                    }
                                    else// compress
                                    {
                                        typename container_t::it_vertex_t iterator_vertex_compress_vertex1 = p_tree_node->arc_backward.head, iterator_vertex_compress_center, iterator_vertex_compress_vertex2 = p_tree_node->arc_forward.head;
                                        if(p_tree_node->child_left()->arc_backward.head == p_tree_node->arc_backward.head)
                                            iterator_vertex_compress_center = p_tree_node->child_left()->arc_forward.head;
                                        else if(p_tree_node->child_left()->arc_forward.head == p_tree_node->arc_backward.head)
                                            iterator_vertex_compress_center = p_tree_node->child_left()->arc_backward.head;
                                        else std::unreachable();
                                        add_vertex_if_not_added_before(iterator_vertex_compress_center);
                                        if(!iterator_vertex_root.has_value())
                                        {
                                            assert(!iterator_vertex_from_excluded.has_value());
                                            assert(!iterator_vertex_to_excluded.has_value());
                                            cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_left(), iterator_vertex_compress_center, iterator_vertex_compress_center, std::nullopt));
                                            cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_right(), iterator_vertex_compress_center, iterator_vertex_compress_center, std::nullopt));
                                        }
                                        else
                                        {
                                            if(iterator_vertex_root.value()==iterator_vertex_compress_vertex1)
                                            {
                                                cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_left(), iterator_vertex_compress_vertex1, iterator_vertex_from_excluded, iterator_vertex_compress_center));
                                                cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_right(), iterator_vertex_compress_center, iterator_vertex_compress_center, iterator_vertex_to_excluded));
                                            }
                                            else if(iterator_vertex_root.value()==iterator_vertex_compress_vertex2)
                                            {
                                                cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_left(), iterator_vertex_compress_center, iterator_vertex_compress_center, iterator_vertex_to_excluded));
                                                cluster_cluster.statements.push_back(tree_node_recursive(p_tree_node->child_right(), iterator_vertex_compress_vertex2, iterator_vertex_from_excluded, iterator_vertex_compress_center));
                                            }
                                            else std::unreachable();
                                        }
                                    }
                                }

                                return cluster_cluster;
                            };

                            g.statements.push_back(tree_node_recursive(p_list_node->tree_root, std::nullopt, std::nullopt, std::nullopt));
                        }

                        std::ranges::copy(vertex_nodes, std::back_inserter(g.statements));
                        std::ranges::copy(edge_nodes, std::back_inserter(g.statements));
                        std::ranges::copy(vertex_edge_edges, std::back_inserter(g.statements));
                        std::ranges::copy(iterator_vertex_nodes, std::back_inserter(g.statements));
                        std::ranges::copy(iterator_vertex_edges, std::back_inserter(g.statements));
                        std::ranges::copy(iterator_edge_nodes, std::back_inserter(g.statements));
                        std::ranges::copy(iterator_edge_edges, std::back_inserter(g.statements));

                        std::ranges::copy(converter_generated_statements, std::back_inserter(g.statements));

                        sub_result.push_back(g);
                    }

                    {
                        std::vector<std::variant<node_statement_t, edge_statement_t, attr_statement_t, attr_t, subgraph_t>> converter_generated_statements;

                        std::vector<node_statement_t> list_nodes;
                        std::vector<edge_statement_t> list_node_edges;
                        std::vector<node_statement_t> tree_nodes;
                        std::vector<edge_statement_t> tree_node_edges;

                        for(typename part_t::cluster_list_node_navigator_t *p_list_node_navigator = part_t::cluster_list_node_navigator_t::untagged_next_or_tagged_end(part.cluster_list_node_end); p_list_node_navigator != part.cluster_list_node_end; p_list_node_navigator = p_list_node_navigator->next)
                        {
                            auto p_list_node = static_cast<typename part_t::cluster_list_node_t *>(p_list_node_navigator);

                            assert(p_list_node->prev != nullptr);
                            if(p_list_node->prev != part.cluster_list_node_end)
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
                            if(p_list_node->next != part.cluster_list_node_end)
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"next", c},
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node->next)},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->next"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                    }}});

                            assert(p_list_node->tree_root != nullptr);
                                list_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"list_node_" + object_pointer_to_string(p_list_node), u8"tree_root", c},
                                                                               node_id_t{u8"tree_node_" + object_pointer_to_string(p_list_node->tree_root)},
                                                                           }},
                                    {{
                                        {u8"id", u8"list_node_" + object_pointer_to_string(p_list_node) + u8"->tree_root"},
                                        {u8"tailclip", u8"false"},
                                    }}});

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
                                                        .COLSPAN = 4,
                                                        .content = html_label_t{pointer_title_text_to_title_only(u8"list_node", object_pointer_to_string(p_list_node))},
                                                    },
                                                }});
                                            result.push_back(row_t{{
                                                cell_t{
                                                    .BGCOLOR = p_list_node->prev == part.cluster_list_node_end ? inactive_cell_color : active_cell_color,
                                                    .COLSPAN = 2,
                                                    .PORT = u8"prev",
                                                    .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"prev", print_object_pointer_t{p_list_node->prev}))},
                                                },
                                                cell_t{
                                                    .BGCOLOR = p_list_node->next == part.cluster_list_node_end ? inactive_cell_color : active_cell_color,
                                                    .COLSPAN = 2,
                                                    .PORT = u8"next",
                                                    .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"next", print_object_pointer_t{p_list_node->next}))},
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
                                                        .PORT = u8"tree_root",
                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"tree_root", print_object_pointer_t{p_list_node->tree_root}))},
                                                    },
                                                    cell_t{
                                                        .COLOR = u8"transparent",
                                                    },
                                                }});
                                            return result; //
                                        }(),
                                    }}}},
                                }}});

                            using cluster_tree_node_t = typename part_t::cluster_tree_node_t;
                            std::function<void(cluster_tree_node_t *)> tree_node_recursive = [&](cluster_tree_node_t *p_tree_node)
                            {
                                assert(p_tree_node->parent != nullptr);
                                tree_node_edges.push_back(edge_statement_t{{{
                                                                               node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"parent", c},
                                                                               node_id_t{tagged_ptr_bit0_is_setted(p_tree_node->parent) ? u8"list_node_" + object_pointer_to_string(tagged_ptr_bit0_unsetted(p_tree_node->parent)) : u8"tree_node_" + object_pointer_to_string(p_tree_node->parent)},
                                                                           }},
                                    {{
                                        {u8"id", u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"->parent"},
                                        {u8"style", tagged_ptr_bit0_is_setted(p_tree_node->parent) ? u8"dashed" : u8"solid"},
                                        {u8"constraint", u8"false"},
                                        {u8"tailclip", u8"false"},
                                    }}});

                                cluster_tree_node_t *child_left = p_tree_node->child_left(), *child_right = p_tree_node->child_right();
                                if(child_left!=nullptr)
                                    tree_node_edges.push_back(edge_statement_t{{{
                                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"child_left", c},
                                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(child_left)},
                                                                               }},
                                        {{
                                            {u8"id", u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"->child_left"},
                                            {u8"tailclip", u8"false"},
                                        }}});
                                if(child_right!=nullptr)
                                    tree_node_edges.push_back(edge_statement_t{{{
                                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"child_right", c},
                                                                                   node_id_t{u8"tree_node_" + object_pointer_to_string(child_right)},
                                                                               }},
                                        {{
                                            {u8"id", u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"->child_right"},
                                            {u8"tailclip", u8"false"},
                                        }}});

                                cluster_tree_node_t *p_tree_node_arc_backward_prev=p_tree_node->arc_backward.prev()->cluster_tree_node();
                                cluster_tree_node_t *p_tree_node_arc_backward_next=p_tree_node->arc_backward.next()->cluster_tree_node();
                                cluster_tree_node_t *p_tree_node_arc_forward_prev=p_tree_node->arc_forward.prev()->cluster_tree_node();
                                cluster_tree_node_t *p_tree_node_arc_forward_next=p_tree_node->arc_forward.next()->cluster_tree_node();
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
                                                result.push_back(row_t{{
                                                    cell_t{
                                                        .BGCOLOR = active_cell_color,
                                                        .COLSPAN = 4,
                                                        .content = html_label_t{fonttable_t{table_t{
                                                            .BORDER = 0,
                                                            .CELLBORDER = 1,
                                                            .CELLSPACING = 0,
                                                            .PORT = u8"arc_backward",
                                                            .rows = [&]()
                                                            {
                                                                decltype(table_t::rows) result;
                                                                result.push_back(
                                                                    row_t{{
                                                                        cell_t{
                                                                            .BGCOLOR = active_cell_color,
                                                                            .BORDER=part.it_vertex_exposed1==p_tree_node->arc_backward.head||part.it_vertex_exposed2==p_tree_node->arc_backward.head?std::make_optional<double>(2):std::nullopt,
                                                                            .COLOR=part.it_vertex_exposed1==p_tree_node->arc_backward.head||part.it_vertex_exposed2==p_tree_node->arc_backward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                            .PORT = u8"arc_backward.head",
                                                                            .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                               .member_name =
#endif
                                                                                    u8"arc_backward.head",
#ifndef __EMSCRIPTEN__
                                                                               .datum =
#endif
                                                                                    p_tree_node->arc_backward.head,
#ifndef __EMSCRIPTEN__
                                                                                .converter_generated_statements_back_inserter =
#endif
                                                                                    std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                                .accumulated_storage_node_type =
#endif
                                                                                    storage_node_type_e::top_tree_cluster_hierarchy_vertex,
                                                                            }),
                                                                        },
                                                                        cell_t{
                                                                            .BGCOLOR = active_cell_color,
                                                                            .PORT = u8"arc_backward.next",
                                                                            .content= html_label_t{text_t{{{p_tree_node_arc_backward_next==p_tree_node ? u8"↓" : u8" "}}}},
                                                                        },
                                                                        cell_t{
                                                                            .BGCOLOR = active_cell_color,
                                                                            .PORT = u8"arc_backward.prev",
                                                                            .content= html_label_t{text_t{{{p_tree_node_arc_backward_prev==p_tree_node ? u8"↓" : u8" "}}}},
                                                                        },
                                                                    }});
                                                                return result; //
                                                            }(),
                                                        }}},
                                                    },
                                                }});
                                                result.push_back(row_t{{
                                                    cell_t{
                                                        .BGCOLOR = active_cell_color,
                                                        .COLSPAN = 4,
                                                        .content = html_label_t{fonttable_t{table_t{
                                                            .BORDER = 0,
                                                            .CELLBORDER = 1,
                                                            .CELLSPACING = 0,
                                                            .PORT = u8"arc_forward",
                                                            .rows = [&]()
                                                            {
                                                                decltype(table_t::rows) result;
                                                                result.push_back(
                                                                    row_t{{
                                                                        cell_t{
                                                                            .BGCOLOR = active_cell_color,
                                                                            .PORT = u8"arc_forward.prev",
                                                                            .content= html_label_t{text_t{{{p_tree_node_arc_forward_prev==p_tree_node ? u8"↑" : u8" "}}}},
                                                                        },
                                                                        cell_t{
                                                                            .BGCOLOR = active_cell_color,
                                                                            .PORT = u8"arc_forward.next",
                                                                            .content= html_label_t{text_t{{{p_tree_node_arc_forward_next==p_tree_node ? u8"↑" : u8" "}}}},
                                                                        },
                                                                        cell_t{
                                                                            .BGCOLOR = active_cell_color,
                                                                            .BORDER=part.it_vertex_exposed1==p_tree_node->arc_forward.head||part.it_vertex_exposed2==p_tree_node->arc_forward.head?std::make_optional<double>(2):std::nullopt,
                                                                            .COLOR=part.it_vertex_exposed1==p_tree_node->arc_forward.head||part.it_vertex_exposed2==p_tree_node->arc_forward.head?std::make_optional<std::u8string>(u8"#FF0000"):std::nullopt,
                                                                            .PORT = u8"arc_forward.head",
                                                                            .content = to_graphs_parameters.vertex_to_string_converter(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                                .member_name =
#endif
                                                                                    u8"arc_forward.head",
#ifndef __EMSCRIPTEN__
                                                                                .datum =
#endif
                                                                                    p_tree_node->arc_forward.head,
#ifndef __EMSCRIPTEN__
                                                                                .converter_generated_statements_back_inserter =
#endif
                                                                                    std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                                .accumulated_storage_node_type =
#endif
                                                                                    storage_node_type_e::top_tree_cluster_hierarchy_vertex,
                                                                            }),
                                                                        },
                                                                    }});
                                                                return result; //
                                                            }(),
                                                        }}},
                                                    },
                                                }});
                                                if constexpr(!std::is_same_v<typename part_t::cluster_t,void>)
                                                    result.push_back(row_t{{
                                                        cell_t{
                                                            .BGCOLOR = active_cell_color,
                                                            .COLSPAN = 4,
                                                            .content = std::get<part_index>(to_graphs_parameters.part_data_to_string_converter_per_part)(to_string_converter_parameters_t{
#ifndef __EMSCRIPTEN__
                                                                .member_name =
#endif
                                                                    u8"cluster",
#ifndef __EMSCRIPTEN__
                                                                .datum =
#endif
                                                                    std::make_tuple(p_tree_node->arc_backward.head, std::cref(*p_tree_node->p_cluster()), p_tree_node->arc_forward.head),
#ifndef __EMSCRIPTEN__
                                                                .converter_generated_statements_back_inserter =
#endif
                                                                    std::back_inserter(converter_generated_statements),
#ifndef __EMSCRIPTEN__
                                                                .accumulated_storage_node_type =
#endif
                                                                    storage_node_type_e::top_tree_cluster_hierarchy_cluster,
                                                            }),
                                                        },
                                                    }});
                                                result.push_back(row_t{{
                                                    cell_t{
                                                        .BGCOLOR = child_left == nullptr ? inactive_cell_color : active_cell_color,
                                                        .COLSPAN = 2,
                                                        .PORT = u8"child_left",
                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"child_left", print_object_pointer_t{child_left}))},
                                                    },
                                                    cell_t{
                                                        .BGCOLOR = child_right == nullptr ? inactive_cell_color : active_cell_color,
                                                        .COLSPAN = 2,
                                                        .PORT = u8"child_right",
                                                        .content = html_label_t{pointer_member_text_to_space(member_to_text(u8"child_right", print_object_pointer_t{child_right}), textitem_t{std::make_pair(font_t{.COLOR = u8"#0000FF", .FACE = u8"Cambria Math"}, text_t{{{[&]()->std::u8string{
                                                            if(child_left==nullptr&&child_right==nullptr)return u8" ";
                                                            else if(child_left!=nullptr&&child_right==nullptr)return u8" ";
                                                            else if(child_left!=nullptr&&child_right!=nullptr)return !p_tree_node->contraction_type()?u8"⤻":u8"→←";
                                                            else std::unreachable();
                                                        }()}}})})},
                                                    },
                                                }});
                                                return result; //
                                            }(),
                                        }}}},
                                    }}});

                                if(p_tree_node_arc_backward_prev!=p_tree_node)
                                    tree_node_edges.push_back(edge_statement_t{{{
                                                                                    node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"arc_backward.prev", c},
                                                                                    node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node_arc_backward_prev),p_tree_node->arc_backward.prev()==&p_tree_node_arc_backward_prev->arc_backward?u8"arc_backward":u8"arc_forward"},
                                                                                }},
                                         {{
                                             {u8"id", u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"->arc_backward.prev"},
                                             {u8"constraint", u8"false"},
                                             {u8"tailclip", u8"false"},
                                         }}});
                                else
                                    assert(p_tree_node->arc_backward.prev()==&p_tree_node_arc_backward_prev->arc_forward);
                                if(p_tree_node_arc_backward_next!=p_tree_node)
                                    tree_node_edges.push_back(edge_statement_t{{{
                                                                                    node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"arc_backward.next", c},
                                                                                    node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node_arc_backward_next),p_tree_node->arc_backward.next()==&p_tree_node_arc_backward_next->arc_backward?u8"arc_backward":u8"arc_forward"},
                                                                                }},
                                         {{
                                             {u8"id", u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"->arc_backward.next"},
                                             {u8"constraint", u8"false"},
                                             {u8"tailclip", u8"false"},
                                         }}});
                                else
                                    assert(p_tree_node->arc_backward.next()==&p_tree_node_arc_backward_next->arc_forward);
                                if(p_tree_node_arc_forward_prev!=p_tree_node)
                                    tree_node_edges.push_back(edge_statement_t{{{
                                                                                    node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"arc_forward.prev", c},
                                                                                    node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node_arc_forward_prev),p_tree_node->arc_forward.prev()==&p_tree_node_arc_forward_prev->arc_backward?u8"arc_backward":u8"arc_forward"},
                                                                                }},
                                         {{
                                             {u8"id", u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"->arc_forward.prev"},
                                             {u8"constraint", u8"false"},
                                             {u8"tailclip", u8"false"},
                                         }}});
                                else
                                    assert(p_tree_node->arc_forward.prev()==&p_tree_node_arc_forward_prev->arc_backward);
                                if(p_tree_node_arc_forward_next!=p_tree_node)
                                    tree_node_edges.push_back(edge_statement_t{{{
                                                                                    node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node), u8"arc_forward.next", c},
                                                                                    node_id_t{u8"tree_node_" + object_pointer_to_string(p_tree_node_arc_forward_next),p_tree_node->arc_forward.next()==&p_tree_node_arc_forward_next->arc_backward?u8"arc_backward":u8"arc_forward"},
                                                                                }},
                                         {{
                                             {u8"id", u8"tree_node_" + object_pointer_to_string(p_tree_node) + u8"->arc_forward.next"},
                                             {u8"constraint", u8"false"},
                                             {u8"tailclip", u8"false"},
                                         }}});
                                else
                                    assert(p_tree_node->arc_forward.next()==&p_tree_node_arc_forward_next->arc_backward);

                                if(child_left!=nullptr)
                                    tree_node_recursive(child_left);
                                if(child_right!=nullptr)
                                    tree_node_recursive(child_right);
                            };
                            tree_node_recursive(p_list_node->tree_root);
                        }

                        graph_t g{
                            .is_strict = false,
                            .is_directed = true,
                            .name = std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "augmented_graph").str().data())),
                            .statements = {
                                attr_t{u8"label", u8""},
                                attr_t{u8"id", u8"graph"},

                                attr_t{u8"compound", u8"true"},
                                attr_t{u8"rankdir", u8"TB"},
                                attr_t{u8"outputorder", u8"nodesfirst"},
                                attr_t{u8"fontname", u8"Consolas"},
                                attr_t{u8"bgcolor", u8"transparent"},
                                attr_t{u8"labeljust", u8"c"},
                                attr_t{u8"labelloc", u8"t"},
                                attr_t{u8"forcelabels", u8"true"},
                                attr_t{u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                attr_t{u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                attr_statement_t{graph, {{
                                                            {u8"compound", u8"true"},
                                                            {u8"rankdir", u8"TB"},
                                                            {u8"outputorder", u8"nodesfirst"},
                                                            {u8"fontname", u8"Consolas"},
                                                            {u8"bgcolor", u8"transparent"},
                                                            {u8"labeljust", u8"c"},
                                                            {u8"labelloc", u8"t"},
                                                            {u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                            {u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                        }}},
                                attr_statement_t{node, {{
                                                           {u8"shape", u8"plain"},
                                                           {u8"fontname", u8"Consolas"},
                                                           {u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                           {u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                       }}},
                                attr_statement_t{edge, {{
                                                            {u8"color", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                            {u8"fontcolor", std::get<part_index>(std::make_tuple(u8"#000000", u8"#0000FF", u8"#00B4B4"))},
                                                        }}},
                            },
                        };

                        std::ranges::copy(list_nodes, std::back_inserter(g.statements));
                        std::ranges::copy(tree_nodes, std::back_inserter(g.statements));
                        std::ranges::copy(list_node_edges, std::back_inserter(g.statements));
                        std::ranges::copy(tree_node_edges, std::back_inserter(g.statements));

                        std::ranges::copy(converter_generated_statements, std::back_inserter(g.statements));

                        sub_result.push_back(g);
                    }

                    result.push_back(sub_result);
                } }());
        }
        (std::make_index_sequence<container_t::parts_count>());

        return result;
    }
} // namespace augmented_containers

#endif // AUGMENTED_GRAPH_VISUALIZATION_HPP
