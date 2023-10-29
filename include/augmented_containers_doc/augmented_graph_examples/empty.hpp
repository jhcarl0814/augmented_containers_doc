
#ifndef AUGMENTED_GRAPH_EXAMPLE_PREFIX
    #define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) id
#endif

#include <augmented_containers/augmented_graph.hpp>
#include <augmented_containers_doc/augmented_graph_visualization.hpp>

struct AUGMENTED_GRAPH_EXAMPLE_PREFIXING(monostate_comparator_t)
{
    bool operator()([[maybe_unused]] std::monostate const &lhs, [[maybe_unused]] std::monostate const &rhs) const { return false; }
};
augmented_containers::augmented_graph_t<
    std::monostate,
    std::monostate,
    std::tuple<>,
    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(monostate_comparator_t),
    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(monostate_comparator_t) //
    >
    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph);
std::size_t AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex)() { return AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).size_vertex(); }
std::size_t AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge)() { return AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).size_edge(); }

std::vector<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_vertex_t> AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex){
    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex(),
    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex(),
};
std::vector<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_edge_it_vertexes_t> AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge){
    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_edge(),
    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge(),
};
std::size_t AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count)() { return AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex).size(); }
std::size_t AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count)() { return AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge).size(); }

void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement)(std::size_t iterator_vertex_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex())
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)
    [iterator_vertex_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex();
    else --AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index];
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment)(std::size_t iterator_vertex_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)
    [iterator_vertex_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex();
    else ++AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index];
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index)(std::size_t iterator_vertex_index, std::size_t index)
{
    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)
    [iterator_vertex_index] = std::ranges::next(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex(), index % (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).vertexes.size() + 1));
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert)(std::size_t iterator_vertex_index)
{
    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)
    [iterator_vertex_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).insert_vertex({});
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase)(std::size_t iterator_vertex_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_vertex_will_be_invalidated;
        std::ranges::transform(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex), std::back_inserter(iterators_vertex_will_be_invalidated), [&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_vertex_t iterator_vertex)
            { return iterator_vertex == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]; });
        std::vector<bool> iterators_edge_will_be_invalidated;
        std::ranges::transform(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge), std::back_inserter(iterators_edge_will_be_invalidated), [&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_edge_it_vertexes_t iterator_edge)
            { return iterator_edge != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge() && (iterator_edge->second.first == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] || iterator_edge->second.second == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]); });
#else
        std::vector<bool> iterators_vertex_will_be_invalidated = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex) | std::views::transform([&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_vertex_t iterator_vertex)
                                                                                                                           { return iterator_vertex == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]; }) |
            std::ranges::to<std::vector>();
        std::vector<bool> iterators_edge_will_be_invalidated = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge) | std::views::transform([&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_edge_it_vertexes_t iterator_edge)
                                                                                                                       { return iterator_edge != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge() && (iterator_edge->second.first == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] || iterator_edge->second.second == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]); }) |
            std::ranges::to<std::vector>();
#endif
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)
        [iterator_vertex_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).erase_vertex(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]);
        std::ranges::for_each(iterators_vertex_will_be_invalidated, [&, index = 0](bool iterator_vertex_will_be_invalidated) mutable
            {if(iterator_vertex_will_be_invalidated)AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[index]=AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index];++index; });
        std::ranges::for_each(iterators_edge_will_be_invalidated, [&, index = 0](bool iterator_edge_will_be_invalidated) mutable
            {if(iterator_edge_will_be_invalidated)AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[index]=AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge();++index; });
    }
}

void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement)(std::size_t iterator_edge_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_edge())
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)
    [iterator_edge_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge();
    else --AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index];
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment)(std::size_t iterator_edge_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge())
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)
    [iterator_edge_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_edge();
    else ++AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index];
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index)(std::size_t iterator_edge_index, std::size_t index)
{
    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)
    [iterator_edge_index] = std::ranges::next(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_edge(), index % (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).edges_it_vertexes.size() + 1));
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert)(std::size_t iterator_edge_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[0] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[1] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)
    [iterator_edge_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).insert_edge(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[0], AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[1], {});
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase)(std::size_t iterator_edge_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge())
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_will_be_invalidated;
        std::ranges::transform(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge), std::back_inserter(iterators_will_be_invalidated), [&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_edge_it_vertexes_t iterator_edge)
            { return iterator_edge == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]; });
#else
        std::vector<bool> iterators_will_be_invalidated = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge) | std::views::transform([&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_edge_it_vertexes_t iterator_edge)
                                                                                                                  { return iterator_edge == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]; }) |
            std::ranges::to<std::vector>();
#endif
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)
        [iterator_edge_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).erase_edge(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]);
        std::ranges::for_each(iterators_will_be_invalidated, [&, index = 0](bool iterator_will_be_invalidated) mutable
            {if(iterator_will_be_invalidated)AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[index]=AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index];++index; });
    }
}

std::vector<std::vector<std::string>> AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string)()
{
    std::vector<std::vector<std::string>> result;
    using namespace dot;
    using namespace augmented_containers::detail::visualization::augmented_graph;
    for(std::vector<dot::graph_t> &graphs : to_graphs(
            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph),
            to_graphs_parameters_t{
                .vertex_to_string_converter = [](auto parameters) -> html_label_t
                { return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "[" << std::ranges::distance(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex(), parameters.datum) << "]").str().data()))}}}}; },
               .edge_to_string_converter = [](auto parameters) -> html_label_t
                { return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "[" << std::ranges::distance(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_edge(), parameters.datum) << "]").str().data()))}}}}; },
               .part_data_to_string_converter_per_part = std::make_tuple(),
               .iterators_vertex = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex),
               .iterators_edge = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge),
            }))
    {
        std::vector<std::string> sub_result;
        for(dot::graph_t &graph : graphs)
        {
            sub_result.push_back((std::ostringstream() << graph).str());
        }
        result.push_back(sub_result);
    }
    return result;
}
