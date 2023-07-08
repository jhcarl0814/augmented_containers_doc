
#ifndef AUGMENTED_GRAPH_EXAMPLE_PREFIX
    #define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) id
#endif

#include "augmented_graph.hpp"
#include "augmented_graph_visualization.hpp"
#include <random>

std::random_device AUGMENTED_GRAPH_EXAMPLE_PREFIXING(rd); // Will be used to obtain a seed for the random number engine
std::mt19937 AUGMENTED_GRAPH_EXAMPLE_PREFIXING(gen)(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(rd)()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> AUGMENTED_GRAPH_EXAMPLE_PREFIXING(distrib)(-10, 10);

struct AUGMENTED_GRAPH_EXAMPLE_PREFIXING(monostate_comparator_t)
{
    bool operator()([[maybe_unused]] std::monostate const &lhs, [[maybe_unused]] std::monostate const &rhs) const { return false; }
};
//using AUGMENTED_GRAPH_EXAMPLE_PREFIXING(type_aliases_t) = augmented_containers::augmented_graph_type_aliases_t<
//    std::monostate,
//    int //
//    >;
augmented_containers::augmented_graph_t<
    std::monostate,
    int,
    std::tuple<
        std::pair<std::integral_constant<augmented_containers::augmented_graph_part_data_structure_e, augmented_containers::augmented_graph_part_data_structure_e::top_tree>, augmented_containers::augmented_graph_helpers::get_top_tree_internal_operations_selecting_path_t<std::less<void>>> //
        >,
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

bool AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_disconnected)(std::size_t part_index, std::size_t iterator_vertex1_index, std::size_t iterator_vertex2_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        bool result;
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (..., [&]()
                {
                if(part_index == I)
                {
                    auto root_cluster_tree_node1 = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().root_cluster_tree_node(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index]), root_cluster_tree_node2 = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().root_cluster_tree_node(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index]);
                    if(!root_cluster_tree_node1.has_value() && !root_cluster_tree_node2.has_value())
                        result = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index];
                    else if(root_cluster_tree_node1.has_value() && root_cluster_tree_node2.has_value())
                        result = root_cluster_tree_node1.value() != root_cluster_tree_node2.value();
                    else
                        result = true;
                } }());
        }
        (std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
        return result;
    }
    else
        return false;
}
bool AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected)(std::size_t part_index, std::size_t iterator_vertex1_index, std::size_t iterator_vertex2_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        bool result;
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (..., [&]()
                {
                if(part_index == I)
                {
                    auto root_cluster_tree_node1 = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().root_cluster_tree_node(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index]), root_cluster_tree_node2 = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().root_cluster_tree_node(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index]);
                    if(!root_cluster_tree_node1.has_value() && !root_cluster_tree_node2.has_value())
                        result = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index];
                    else if(root_cluster_tree_node1.has_value() && root_cluster_tree_node2.has_value())
                        result = root_cluster_tree_node1.value() == root_cluster_tree_node2.value();
                    else
                        result = false;
                } }());
        }
        (std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
        return result;
    }
    else
        return false;
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
    [iterator_edge_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).insert_edge(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[0], AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[1], AUGMENTED_GRAPH_EXAMPLE_PREFIXING(distrib)(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(gen)));
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
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update)(std::size_t iterator_edge_index, std::string value)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge())
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).update_edge(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index], [&value](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::edge_t &edge)
            {
            int value_int;
            std::istringstream(value) >> value_int;
            edge = value_int; });
}

void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose)(std::size_t part_index, std::size_t iterator_vertex_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (..., [&]()
                {
                if(part_index == I)
                {
                    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] &&
                        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index])
                        ;
                    else
                        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]);
                } }());
        }
        (std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose)(std::size_t part_index, std::size_t iterator_vertex_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (..., [&]()
                {
                if(part_index == I)
                {
                    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1 == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] ||
                        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2 == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index])
                        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().unexpose(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]);
                } }());
        }
        (std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace)(std::size_t part_index, std::size_t iterator_vertex_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (..., [&]()
                {
                if(part_index == I)
                {
                    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose_replace(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]);
                } }());
        }
        (std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose)(std::size_t part_index, std::size_t iterator_vertex1_index, std::size_t iterator_vertex2_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (..., [&]()
                {
                if(part_index == I)
                {
                    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index]==AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index])
                    {
                        if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] &&
                            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index])
                            ;
                        else
                            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index], AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index]);
                    }
                    else
                    {
                        if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index] ||
                            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index])
                            ;
                        else
                            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index], AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index]);
                    }
                } }());
        }
        (std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace)(std::size_t part_index, std::size_t iterator_vertex1_index, std::size_t iterator_vertex2_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (..., [&]()
                {
                if(part_index == I)
                {
                    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose_replace(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index], AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index]);
                } }());
        }
        (std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose)(std::size_t part_index, std::size_t iterator_edge_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (..., [&]()
                {
                if(part_index == I)
                {
                    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first==AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.second)
                    {
                        if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first &&
                            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first)
                            ;
                        else
                            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first, AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.second);
                    }
                    else
                    {
                        if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.second ||
                            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.second)
                            ;
                        else
                            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first, AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.second);
                    }
                } }());
        }
        (std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace)(std::size_t part_index, std::size_t iterator_edge_index)
{
    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>)
        {
            (..., [&]()
                {
                if(part_index == I)
                {
                    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose_replace(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first, AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.second);
                } }());
        }
        (std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose)(std::size_t part_index)
{
    [&]<std::size_t... I>(std::index_sequence<I...>)
    {
        (..., [&]()
            {
            if(part_index == I)
            {
                AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().unexpose();
            } }());
    }
    (std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
}

std::vector<std::vector<std::string>> AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string)()
{
    std::vector<std::vector<std::string>> result;
    using namespace dot;
    using namespace augmented_containers::detail::visualization::augmented_graph;
    for(std::vector<dot::graph_t> &graphs : to_graphs(
            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph),
            to_graphs_parameters_t{
#ifndef __EMSCRIPTEN__
                .vertex_to_string_converter =
#endif
                    [](auto parameters) -> html_label_t
                { return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "[" << std::ranges::distance(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex(), parameters.datum) << "]").str().data()))}}}}; },
#ifndef __EMSCRIPTEN__
               .edge_to_string_converter =
#endif
                    [](auto parameters) -> html_label_t
                {
                    switch(parameters.accumulated_storage_node_type)
                    {
                    case storage_node_type_e::edge:
                    case storage_node_type_e::top_tree_graph_edge:
                        return html_label_t{text_t{{
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "[" << std::ranges::distance(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_edge(), parameters.datum) << "]:").str().data()))},
                            {br_t{}},
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << parameters.datum->first).str().data()))},
                            {br_t{}},
                        }}};
                    case storage_node_type_e::top_tree_graph_hierarchy_edge:
                        return html_label_t{text_t{{
                            {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "[" << std::ranges::distance(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_edge(), parameters.datum) << "]: " << parameters.datum->first).str().data()))},
                            {br_t{}},
                        }}};
                        break;
                    default:
                        std::unreachable();
                        break;
                    }
                },
#ifndef __EMSCRIPTEN__
               .part_data_to_string_converter_per_part =
#endif
                    std::make_tuple([](auto parameters) -> html_label_t
                        {
                        auto [it_vertex_backward, cluster, it_vertex_forward] = parameters.datum;
                        return html_label_t{text_t{{
                              {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "[" << std::ranges::distance(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_edge(), cluster) << "]: " << cluster->first).str().data()))},
                          }}}; }),
#ifndef __EMSCRIPTEN__
               .iterators_vertex =
#endif
                    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex),
#ifndef __EMSCRIPTEN__
               .iterators_edge =
#endif
                    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge),
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
