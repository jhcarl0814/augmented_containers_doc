
#ifndef AUGMENTED_GRAPH_EXAMPLE_PREFIX
    #define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) id
#endif

#include <augmented_containers/augmented_graph.hpp>
#include <augmented_containers_doc/augmented_graph_visualization.hpp>

#include <random>

std::random_device AUGMENTED_GRAPH_EXAMPLE_PREFIXING(rd); // Will be used to obtain a seed for the random number engine
std::mt19937 AUGMENTED_GRAPH_EXAMPLE_PREFIXING(gen)(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(rd)()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> AUGMENTED_GRAPH_EXAMPLE_PREFIXING(distrib)(-10, 10);

template<typename length_t_>
struct AUGMENTED_GRAPH_EXAMPLE_PREFIXING(get_top_tree_internal_operations_nearest_marked_vertices_t)
{
    template<typename graph_t>
    struct type
    {
        using length_t = length_t_;
        struct cluster_t
        {
            length_t distance;
            std::optional<length_t> distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward, distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward;
            std::set<typename graph_t::it_vertex_t, std::reference_wrapper<typename graph_t::comparator_it_vertex_address_t const>> nearest_marked_vertexes_except_boundary_vertexes_vertex_backward, nearest_marked_vertexes_except_boundary_vertexes_vertex_forward;
        };
        void create([[maybe_unused]] graph_t *graph, [[maybe_unused]] graph_t::it_vertex_t it_vertex1, cluster_t *cluster, [[maybe_unused]] graph_t::it_vertex_t it_vertex2, graph_t::it_edge_it_vertexes_t it_edge_it_vertexes) const
        {
            new (cluster) cluster_t{
                .distance = it_edge_it_vertexes->first,
                .distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward = std::nullopt,
                .distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward = std::nullopt,
                .nearest_marked_vertexes_except_boundary_vertexes_vertex_backward = decltype(cluster_t::nearest_marked_vertexes_except_boundary_vertexes_vertex_backward)(std::cref(graph->comparator_it_vertex_address)),
                .nearest_marked_vertexes_except_boundary_vertexes_vertex_forward = decltype(cluster_t::nearest_marked_vertexes_except_boundary_vertexes_vertex_forward)(std::cref(graph->comparator_it_vertex_address)),
            };
        };
        void destroy([[maybe_unused]] graph_t *graph, [[maybe_unused]] graph_t::it_vertex_t it_vertex1, cluster_t *cluster, [[maybe_unused]] graph_t::it_vertex_t it_vertex2) const
        {
            cluster->~cluster_t();
        };
        void join(graph_t *graph, cluster_t *cluster_parent, graph_t::it_vertex_t it_vertex1, cluster_t *cluster_child_left, graph_t::it_vertex_t it_vertex2, cluster_t *cluster_child_right, graph_t::it_vertex_t it_vertex3, int dummy_or_rake_or_compress) const
        {
            if (dummy_or_rake_or_compress == 0)
                new (cluster_parent) cluster_t(std::as_const(*cluster_child_left));
            else if (dummy_or_rake_or_compress == 1)
            {
                std::optional<length_t> distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left;
                std::set<typename graph_t::it_vertex_t, std::reference_wrapper<typename graph_t::comparator_it_vertex_address_t const>> *p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left;
                if (std::as_const(graph->comparator_it_vertex_address)(it_vertex1, it_vertex2))
                    std::tie(distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left, p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left) = std::make_tuple(cluster_child_left->distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward, &cluster_child_left->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward);
                else if (std::as_const(graph->comparator_it_vertex_address)(it_vertex2, it_vertex1))
                    std::tie(distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left, p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left) = std::make_tuple(cluster_child_left->distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward, &cluster_child_left->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward);
                else std::unreachable();

                std::optional<length_t> distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right;
                std::set<typename graph_t::it_vertex_t, std::reference_wrapper<typename graph_t::comparator_it_vertex_address_t const>> *p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right;
                if (std::as_const(graph->comparator_it_vertex_address)(it_vertex2, it_vertex3))
                    std::tie(distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right, p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right) = std::make_tuple(cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward, &cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward);
                else if (std::as_const(graph->comparator_it_vertex_address)(it_vertex3, it_vertex2))
                    std::tie(distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right, p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right) = std::make_tuple(cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward, &cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward);
                else std::unreachable();

                std::optional<length_t> distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward, distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward;
                std::set<typename graph_t::it_vertex_t, std::reference_wrapper<typename graph_t::comparator_it_vertex_address_t const>> nearest_marked_vertexes_except_boundary_vertexes_vertex_backward(std::cref(graph->comparator_it_vertex_address)), nearest_marked_vertexes_except_boundary_vertexes_vertex_forward(std::cref(graph->comparator_it_vertex_address));
                if (std::as_const(graph->comparator_it_vertex_address)(it_vertex2, it_vertex3))
                {
                    distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward =
                        std::ranges::min({
                                             *it_vertex1 ? std::make_optional(cluster_child_left->distance) : std::nullopt,
                                             distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left,
                                             distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right,
                                         },
                                         [](std::optional<length_t> const &lhs, std::optional<length_t> const &rhs) { return lhs.has_value() && (!rhs.has_value() || lhs.value() < rhs.value()); });
                    if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward.has_value())
                    {
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == (*it_vertex1 ? std::make_optional(cluster_child_left->distance) : std::nullopt))
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(it_vertex1);
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left)
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->begin(), p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert_range(*p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left);
#endif
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right)
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right->begin(), p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right->end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert_range(*p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right);
#endif
                    }

                    distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward =
                        std::ranges::min({
                                             *it_vertex1 ? std::make_optional(cluster_child_left->distance + cluster_child_right->distance) : std::nullopt,
                                             distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left.transform([&](length_t length) { return length + cluster_child_right->distance; }),
                                             cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward,
                                         },
                                         [](std::optional<length_t> const &lhs, std::optional<length_t> const &rhs) { return lhs.has_value() && (!rhs.has_value() || lhs.value() < rhs.value()); });
                    if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward.has_value())
                    {
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == (*it_vertex1 ? std::make_optional(cluster_child_left->distance + cluster_child_right->distance) : std::nullopt))
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(it_vertex1);
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left.transform([&](length_t length) { return length + cluster_child_right->distance; }))
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->begin(), p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert_range(*p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left);
#endif
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward)
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.begin(), cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert_range(cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward);
#endif
                    }
                }
                else if (std::as_const(graph->comparator_it_vertex_address)(it_vertex3, it_vertex2))
                {
                    distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward =
                        std::ranges::min({
                                             *it_vertex1 ? std::make_optional(cluster_child_left->distance) : std::nullopt,
                                             distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left,
                                             distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right,
                                         },
                                         [](std::optional<length_t> const &lhs, std::optional<length_t> const &rhs) { return lhs.has_value() && (!rhs.has_value() || lhs.value() < rhs.value()); });
                    if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward.has_value())
                    {
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == (*it_vertex1 ? std::make_optional(cluster_child_left->distance) : std::nullopt))
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(it_vertex1);
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left)
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->begin(), p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert_range(*p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left);
#endif
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right)
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right->begin(), p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right->end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert_range(*p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right);
#endif
                    }

                    distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward =
                        std::ranges::min({
                                             *it_vertex1 ? std::make_optional(cluster_child_left->distance + cluster_child_right->distance) : std::nullopt,
                                             distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left.transform([&](length_t length) { return length + cluster_child_right->distance; }),
                                             cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward,
                                         },
                                         [](std::optional<length_t> const &lhs, std::optional<length_t> const &rhs) { return lhs.has_value() && (!rhs.has_value() || lhs.value() < rhs.value()); });
                    if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward.has_value())
                    {
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == (*it_vertex1 ? std::make_optional(cluster_child_left->distance + cluster_child_right->distance) : std::nullopt))
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(it_vertex1);
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left.transform([&](length_t length) { return length + cluster_child_right->distance; }))
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->begin(), p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert_range(*p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left);
#endif
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward)
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.begin(), cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert_range(cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward);
#endif
                    }
                }
                else std::unreachable();

                new (cluster_parent) cluster_t{
                    .distance = cluster_child_right->distance,
                    .distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward = distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward,
                    .distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward = distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward,
                    .nearest_marked_vertexes_except_boundary_vertexes_vertex_backward = std::move(nearest_marked_vertexes_except_boundary_vertexes_vertex_backward),
                    .nearest_marked_vertexes_except_boundary_vertexes_vertex_forward = std::move(nearest_marked_vertexes_except_boundary_vertexes_vertex_forward),
                };
            }
            else if (dummy_or_rake_or_compress == 2)
            {
                assert(std::as_const(graph->comparator_it_vertex_address)(it_vertex1, it_vertex3));

                std::optional<length_t> distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left;
                std::set<typename graph_t::it_vertex_t, std::reference_wrapper<typename graph_t::comparator_it_vertex_address_t const>> *p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left;
                if (std::as_const(graph->comparator_it_vertex_address)(it_vertex1, it_vertex2))
                    std::tie(distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left, p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left) = std::make_tuple(cluster_child_left->distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward, &cluster_child_left->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward);
                else if (std::as_const(graph->comparator_it_vertex_address)(it_vertex2, it_vertex1))
                    std::tie(distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left, p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left) = std::make_tuple(cluster_child_left->distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward, &cluster_child_left->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward);
                else std::unreachable();

                std::optional<length_t> distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right;
                std::set<typename graph_t::it_vertex_t, std::reference_wrapper<typename graph_t::comparator_it_vertex_address_t const>> *p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right;
                if (std::as_const(graph->comparator_it_vertex_address)(it_vertex2, it_vertex3))
                    std::tie(distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right, p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right) = std::make_tuple(cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward, &cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward);
                else if (std::as_const(graph->comparator_it_vertex_address)(it_vertex3, it_vertex2))
                    std::tie(distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right, p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right) = std::make_tuple(cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward, &cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward);
                else std::unreachable();

                std::optional<length_t> distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward, distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward;
                std::set<typename graph_t::it_vertex_t, std::reference_wrapper<typename graph_t::comparator_it_vertex_address_t const>> nearest_marked_vertexes_except_boundary_vertexes_vertex_backward(std::cref(graph->comparator_it_vertex_address)), nearest_marked_vertexes_except_boundary_vertexes_vertex_forward(std::cref(graph->comparator_it_vertex_address));
                if (std::as_const(graph->comparator_it_vertex_address)(it_vertex1, it_vertex2))
                {
                    distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward =
                        std::ranges::min({
                                             *it_vertex2 ? std::make_optional(cluster_child_left->distance) : std::nullopt,
                                             cluster_child_left->distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward,
                                             distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right.transform([&](length_t length) { return length + cluster_child_left->distance; }),
                                         },
                                         [](std::optional<length_t> const &lhs, std::optional<length_t> const &rhs) { return lhs.has_value() && (!rhs.has_value() || lhs.value() < rhs.value()); });
                    if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward.has_value())
                    {
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == (*it_vertex2 ? std::make_optional(cluster_child_left->distance) : std::nullopt))
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(it_vertex2);
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == cluster_child_left->distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward)
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(cluster_child_left->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.begin(), cluster_child_left->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert_range(cluster_child_left->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward);
#endif
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right.transform([&](length_t length) { return length + cluster_child_left->distance; }))
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right->begin(), p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right->end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert_range(*p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right);
#endif
                    }
                }
                else if (std::as_const(graph->comparator_it_vertex_address)(it_vertex2, it_vertex1))
                {
                    distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward =
                        std::ranges::min({
                                             *it_vertex2 ? std::make_optional(cluster_child_left->distance) : std::nullopt,
                                             cluster_child_left->distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward,
                                             distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right.transform([&](length_t length) { return length + cluster_child_left->distance; }),
                                         },
                                         [](std::optional<length_t> const &lhs, std::optional<length_t> const &rhs) { return lhs.has_value() && (!rhs.has_value() || lhs.value() < rhs.value()); });
                    if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward.has_value())
                    {
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == (*it_vertex2 ? std::make_optional(cluster_child_left->distance) : std::nullopt))
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(it_vertex2);
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == cluster_child_left->distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward)
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(cluster_child_left->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.begin(), cluster_child_left->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert_range(cluster_child_left->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward);
#endif
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward == distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_right.transform([&](length_t length) { return length + cluster_child_left->distance; }))
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert(p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right->begin(), p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right->end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.insert_range(*p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_right);
#endif
                    }
                }
                else std::unreachable();
                if (std::as_const(graph->comparator_it_vertex_address)(it_vertex2, it_vertex3))
                {
                    distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward =
                        std::ranges::min({
                                             *it_vertex2 ? std::make_optional(cluster_child_right->distance) : std::nullopt,
                                             cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward,
                                             distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left.transform([&](length_t length) { return length + cluster_child_right->distance; }),
                                         },
                                         [](std::optional<length_t> const &lhs, std::optional<length_t> const &rhs) { return lhs.has_value() && (!rhs.has_value() || lhs.value() < rhs.value()); });
                    if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward.has_value())
                    {
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == (*it_vertex2 ? std::make_optional(cluster_child_right->distance) : std::nullopt))
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(it_vertex2);
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward)
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.begin(), cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert_range(cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_forward);
#endif
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left.transform([&](length_t length) { return length + cluster_child_right->distance; }))
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->begin(), p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert_range(*p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left);
#endif
                    }
                }
                else if (std::as_const(graph->comparator_it_vertex_address)(it_vertex3, it_vertex2))
                {
                    distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward =
                        std::ranges::min({
                                             *it_vertex2 ? std::make_optional(cluster_child_right->distance) : std::nullopt,
                                             cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward,
                                             distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left.transform([&](length_t length) { return length + cluster_child_right->distance; }),
                                         },
                                         [](std::optional<length_t> const &lhs, std::optional<length_t> const &rhs) { return lhs.has_value() && (!rhs.has_value() || lhs.value() < rhs.value()); });
                    if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward.has_value())
                    {
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == (*it_vertex2 ? std::make_optional(cluster_child_right->distance) : std::nullopt))
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(it_vertex2);
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == cluster_child_right->distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward)
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.begin(), cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert_range(cluster_child_right->nearest_marked_vertexes_except_boundary_vertexes_vertex_backward);
#endif
                        if (distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward == distance_to_marked_vertexes_except_boundary_vertexes_vertex2_child_left.transform([&](length_t length) { return length + cluster_child_right->distance; }))
#ifdef __EMSCRIPTEN__
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert(p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->begin(), p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left->end());
#else
                            nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.insert_range(*p_nearest_marked_vertexes_except_boundary_vertexes_vertex2_child_left);
#endif
                    }
                }
                else std::unreachable();

                new (cluster_parent) cluster_t{
                    .distance = cluster_child_left->distance + cluster_child_right->distance,
                    .distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward = distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward,
                    .distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward = distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward,
                    .nearest_marked_vertexes_except_boundary_vertexes_vertex_backward = std::move(nearest_marked_vertexes_except_boundary_vertexes_vertex_backward),
                    .nearest_marked_vertexes_except_boundary_vertexes_vertex_forward = std::move(nearest_marked_vertexes_except_boundary_vertexes_vertex_forward),
                };
            }
            else std::unreachable();
        }
        void split([[maybe_unused]] graph_t *graph, cluster_t *cluster_parent, [[maybe_unused]] graph_t::it_vertex_t it_vertex1, [[maybe_unused]] cluster_t *cluster_child_left, [[maybe_unused]] graph_t::it_vertex_t it_vertex2, [[maybe_unused]] cluster_t *cluster_child_right, [[maybe_unused]] graph_t::it_vertex_t it_vertex3, [[maybe_unused]] int dummy_or_rake_or_compress) const
        {
            cluster_parent->~cluster_t();
        };
    };
};
augmented_containers::augmented_graph_t<
    bool,
    int,
    std::tuple<
        std::pair<std::integral_constant<augmented_containers::augmented_graph_part_data_structure_e, augmented_containers::augmented_graph_part_data_structure_e::top_tree>, AUGMENTED_GRAPH_EXAMPLE_PREFIXING(get_top_tree_internal_operations_nearest_marked_vertices_t) < int>> //
    > //
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
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex())
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)
    [iterator_vertex_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex();
    else --AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index];
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment)(std::size_t iterator_vertex_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
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
    [iterator_vertex_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).insert_vertex(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(distrib)(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(gen)) % 3 == 0);
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase)(std::size_t iterator_vertex_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_vertex_will_be_invalidated;
        std::ranges::transform(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex), std::back_inserter(iterators_vertex_will_be_invalidated), [&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_vertex_t iterator_vertex) { return iterator_vertex == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]; });
        std::vector<bool> iterators_edge_will_be_invalidated;
        std::ranges::transform(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge), std::back_inserter(iterators_edge_will_be_invalidated), [&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_edge_it_vertexes_t iterator_edge) { return iterator_edge != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge() && (iterator_edge->second.first == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] || iterator_edge->second.second == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]); });
#else
        std::vector<bool> iterators_vertex_will_be_invalidated = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex) | std::views::transform([&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_vertex_t iterator_vertex) { return iterator_vertex == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]; }) |
            std::ranges::to<std::vector>();
        std::vector<bool> iterators_edge_will_be_invalidated = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge) | std::views::transform([&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_edge_it_vertexes_t iterator_edge) { return iterator_edge != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge() && (iterator_edge->second.first == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] || iterator_edge->second.second == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]); }) |
            std::ranges::to<std::vector>();
#endif
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)
        [iterator_vertex_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).erase_vertex(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]);
        std::ranges::for_each(iterators_vertex_will_be_invalidated, [&, index = 0](bool iterator_vertex_will_be_invalidated) mutable {if(iterator_vertex_will_be_invalidated)AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[index]=AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index];++index; });
        std::ranges::for_each(iterators_edge_will_be_invalidated, [&, index = 0](bool iterator_edge_will_be_invalidated) mutable {if(iterator_edge_will_be_invalidated)AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[index]=AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge();++index; });
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_update)(std::size_t iterator_vertex_index, std::string value)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).update_vertex(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index], [&value](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::vertex_t &vertex) {
            bool value_bool;
            std::istringstream(value) >> std::boolalpha >> value_bool;
            vertex = value_bool; });
}

bool AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_disconnected)(std::size_t part_index, std::size_t iterator_vertex1_index, std::size_t iterator_vertex2_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        bool result;
        [&]<std::size_t... I>(std::index_sequence<I...>) {
            (..., [&]() {
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
        }(std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
        return result;
    }
    else
        return false;
}
bool AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected)(std::size_t part_index, std::size_t iterator_vertex1_index, std::size_t iterator_vertex2_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        bool result;
        [&]<std::size_t... I>(std::index_sequence<I...>) {
            (..., [&]() {
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
        }(std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
        return result;
    }
    else
        return false;
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement)(std::size_t iterator_edge_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_edge())
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)
    [iterator_edge_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge();
    else --AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index];
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment)(std::size_t iterator_edge_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge())
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
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[0] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[1] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)
    [iterator_edge_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).insert_edge(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[0], AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[1], AUGMENTED_GRAPH_EXAMPLE_PREFIXING(distrib)(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(gen)));
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase)(std::size_t iterator_edge_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge())
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_will_be_invalidated;
        std::ranges::transform(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge), std::back_inserter(iterators_will_be_invalidated), [&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_edge_it_vertexes_t iterator_edge) { return iterator_edge == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]; });
#else
        std::vector<bool> iterators_will_be_invalidated = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge) | std::views::transform([&](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_edge_it_vertexes_t iterator_edge) { return iterator_edge == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]; }) |
            std::ranges::to<std::vector>();
#endif
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)
        [iterator_edge_index] = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).erase_edge(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]);
        std::ranges::for_each(iterators_will_be_invalidated, [&, index = 0](bool iterator_will_be_invalidated) mutable {if(iterator_will_be_invalidated)AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[index]=AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index];++index; });
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update)(std::size_t iterator_edge_index, std::string value)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge())
        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).update_edge(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index], [&value](decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::edge_t &edge) {
            int value_int;
            std::istringstream(value) >> value_int;
            edge = value_int; });
}

void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose)(std::size_t part_index, std::size_t iterator_vertex_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>) {
            (..., [&]() {
                if(part_index == I)
                {
                    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] &&
                        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index])
                        ;
                    else
                        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]);
                } }());
        }(std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose)(std::size_t part_index, std::size_t iterator_vertex_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>) {
            (..., [&]() {
                if(part_index == I)
                {
                    if(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1 == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] ||
                        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2 == AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index])
                        AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().unexpose(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]);
                } }());
        }(std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace)(std::size_t part_index, std::size_t iterator_vertex_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>) {
            (..., [&]() {
                if(part_index == I)
                {
                    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose_replace(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex_index]);
                } }());
        }(std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose)(std::size_t part_index, std::size_t iterator_vertex1_index, std::size_t iterator_vertex2_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>) {
            (..., [&]() {
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
                        if((AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index]) ||
                            (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index]))
                            ;
                        else
                            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index], AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index]);
                    }
                } }());
        }(std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace)(std::size_t part_index, std::size_t iterator_vertex1_index, std::size_t iterator_vertex2_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_vertex())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>) {
            (..., [&]() {
                if(part_index == I)
                {
                    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose_replace(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex1_index], AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex)[iterator_vertex2_index]);
                } }());
        }(std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose)(std::size_t part_index, std::size_t iterator_edge_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>) {
            (..., [&]() {
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
                        if((AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed1.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.second) ||
                            (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.has_value() && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first && AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().it_vertex_exposed2.value() != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.second))
                            ;
                        else
                            AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first, AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.second);
                    }
                } }());
        }(std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace)(std::size_t part_index, std::size_t iterator_edge_index)
{
    if (AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index] != AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).end_edge())
    {
        [&]<std::size_t... I>(std::index_sequence<I...>) {
            (..., [&]() {
                if(part_index == I)
                {
                    AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().expose_replace(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.first, AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge)[iterator_edge_index]->second.second);
                } }());
        }(std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
    }
}
void AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose)(std::size_t part_index)
{
    [&]<std::size_t... I>(std::index_sequence<I...>) {
        (..., [&]() {
            if(part_index == I)
            {
                AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).part<I>().unexpose();
            } }());
    }(std::make_index_sequence<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::parts_count>());
}

dot::html_label_t AUGMENTED_GRAPH_EXAMPLE_PREFIXING(C1001)(auto parameters)
{
    using namespace dot;
    using namespace augmented_containers::detail::visualization::augmented_graph;
    auto [it_vertex_backward, cluster, it_vertex_forward] = parameters.datum;
    return html_label_t{fonttable_t{table_t{
        .BORDER = 0,
        .CELLBORDER = 1,
        .CELLSPACING = 0,
        .rows = [&]() {
            decltype(table_t::rows) result;
            result.push_back(row_t{
                {
                 cell_t{
                 .COLSPAN = 2,
                 .content = html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "d(v1,v2): " << cluster.distance).str().data()))}}}},
                 },
                 }
            });

            std::string md1;
            if (!cluster.distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward.has_value())
                md1 = "/";
            else
                md1 = (std::ostringstream() << cluster.distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward.value()).str();
            std::optional<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::part_t<0>::internal_operations_t::length_t> distance_to_marked_vertexes_vertex_backward = std::ranges::min(
                {
                    *it_vertex_backward ? std::make_optional(decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::part_t<0>::internal_operations_t::length_t(0)) : std::nullopt,
                    cluster.distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward,
                    *it_vertex_forward ? std::make_optional(cluster.distance) : std::nullopt,
                },
                [](std::optional<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::part_t<0>::internal_operations_t::length_t> const &lhs, std::optional<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::part_t<0>::internal_operations_t::length_t> const &rhs) { return lhs.has_value() && (!rhs.has_value() || lhs.value() < rhs.value()); }
            );
            std::ostringstream oss_vs1;
            oss_vs1 << "{";
            for (decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_vertex_t v1 : cluster.nearest_marked_vertexes_except_boundary_vertexes_vertex_backward)
                oss_vs1 << "[" << std::ranges::distance(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex(), v1) << "],";
            oss_vs1 << "}";
            std::string MD1;
            if (!distance_to_marked_vertexes_vertex_backward.has_value())
                MD1 = "/";
            else
                MD1 = (std::ostringstream() << distance_to_marked_vertexes_vertex_backward.value()).str();
            std::set<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_vertex_t, std::reference_wrapper<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::comparator_it_vertex_address_t const>> VS1(std::cref(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).comparator_it_vertex_address));
            if (distance_to_marked_vertexes_vertex_backward.has_value())
            {
                if (distance_to_marked_vertexes_vertex_backward == (*it_vertex_backward ? std::make_optional(decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::part_t<0>::internal_operations_t::length_t(0)) : std::nullopt))
                    VS1.insert(it_vertex_backward);
                if (distance_to_marked_vertexes_vertex_backward == cluster.distance_to_marked_vertexes_except_boundary_vertexes_vertex_backward)
#ifdef __EMSCRIPTEN__
                    VS1.insert(cluster.nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.begin(), cluster.nearest_marked_vertexes_except_boundary_vertexes_vertex_backward.end());
#else
                    VS1.insert_range(cluster.nearest_marked_vertexes_except_boundary_vertexes_vertex_backward);
#endif
                if (distance_to_marked_vertexes_vertex_backward == (*it_vertex_forward ? std::make_optional(cluster.distance) : std::nullopt))
                    VS1.insert(it_vertex_forward);
            }
            std::ostringstream oss_VS1;
            oss_VS1 << "{";
            for (decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_vertex_t V1 : VS1)
                oss_VS1 << "[" << std::ranges::distance(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex(), V1) << "],";
            oss_VS1 << "}";

            std::string md2;
            if (!cluster.distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward.has_value())
                md2 = "/";
            else
                md2 = (std::ostringstream() << cluster.distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward.value()).str();
            std::optional<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::part_t<0>::internal_operations_t::length_t> distance_to_marked_vertexes_vertex_forward = std::ranges::min(
                {
                    *it_vertex_forward ? std::make_optional(decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::part_t<0>::internal_operations_t::length_t(0)) : std::nullopt,
                    cluster.distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward,
                    *it_vertex_backward ? std::make_optional(cluster.distance) : std::nullopt,
                },
                [](std::optional<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::part_t<0>::internal_operations_t::length_t> const &lhs, std::optional<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::part_t<0>::internal_operations_t::length_t> const &rhs) { return lhs.has_value() && (!rhs.has_value() || lhs.value() < rhs.value()); }
            );
            std::ostringstream oss_vs2;
            oss_vs2 << "{";
            for (decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_vertex_t v2 : cluster.nearest_marked_vertexes_except_boundary_vertexes_vertex_forward)
                oss_vs2 << "[" << std::ranges::distance(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex(), v2) << "],";
            oss_vs2 << "}";
            std::string MD2;
            if (!distance_to_marked_vertexes_vertex_forward.has_value())
                MD2 = "/";
            else
                MD2 = (std::ostringstream() << distance_to_marked_vertexes_vertex_forward.value()).str();
            std::set<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_vertex_t, std::reference_wrapper<decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::comparator_it_vertex_address_t const>> VS2(std::cref(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).comparator_it_vertex_address));
            if (distance_to_marked_vertexes_vertex_forward.has_value())
            {
                if (distance_to_marked_vertexes_vertex_forward == (*it_vertex_forward ? std::make_optional(decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::part_t<0>::internal_operations_t::length_t(0)) : std::nullopt))
                    VS2.insert(it_vertex_forward);
                if (distance_to_marked_vertexes_vertex_forward == cluster.distance_to_marked_vertexes_except_boundary_vertexes_vertex_forward)
#ifdef __EMSCRIPTEN__
                    VS2.insert(cluster.nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.begin(), cluster.nearest_marked_vertexes_except_boundary_vertexes_vertex_forward.end());
#else
                    VS2.insert_range(cluster.nearest_marked_vertexes_except_boundary_vertexes_vertex_forward);
#endif
                if (distance_to_marked_vertexes_vertex_forward == (*it_vertex_backward ? std::make_optional(cluster.distance) : std::nullopt))
                    VS2.insert(it_vertex_backward);
            }
            std::ostringstream oss_VS2;
            oss_VS2 << "{";
            for (decltype(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph))::it_vertex_t V2 : VS2)
                oss_VS2 << "[" << std::ranges::distance(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex(), V2) << "],";
            oss_VS2 << "}";

            text_t text1_C1001{
                {
                 {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "md(v1): " << md1).str().data()))},
                 {br_t{}},
                 {std::u8string(reinterpret_cast<char8_t const *>(oss_vs1.str().data()))},
                 {br_t{}},
                 textitem_t{std::make_pair(font_t{.COLOR = u8"#00000060"}, text_t{{
                 {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "MD(v1): " << MD1).str().data()))},
                 {br_t{}},
                 {std::u8string(reinterpret_cast<char8_t const *>(oss_VS1.str().data()))},
                 {br_t{}},
                 }})},
                 }
            };
            text_t text2_C1001{
                {
                 {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "md(v2): " << md2).str().data()))},
                 {br_t{}},
                 {std::u8string(reinterpret_cast<char8_t const *>(oss_vs2.str().data()))},
                 {br_t{}},
                 textitem_t{std::make_pair(font_t{.COLOR = u8"#00000060"}, text_t{{
                 {std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "MD(v2): " << MD2).str().data()))},
                 {br_t{}},
                 {std::u8string(reinterpret_cast<char8_t const *>(oss_VS2.str().data()))},
                 {br_t{}},
                 }})},
                 }
            };
            result.push_back(row_t{
                {
                 cell_t{
                 .content = html_label_t{text1_C1001},
                 },
                 cell_t{
                 .content = html_label_t{text2_C1001},
                 },
                 }
            });
            return result; //
        }(),
    }}};
}
std::vector<std::vector<std::string>> AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string)()
{
    std::vector<std::vector<std::string>> result;
    using namespace dot;
    using namespace augmented_containers::detail::visualization::augmented_graph;
    for (std::vector<dot::graph_t> &graphs : to_graphs(
             AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph),
             to_graphs_parameters_t{
                 .vertex_to_string_converter = [](auto parameters) -> html_label_t { return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << "[" << std::ranges::distance(AUGMENTED_GRAPH_EXAMPLE_PREFIXING(augmented_graph).begin_vertex(), parameters.datum) << "]:" << (*parameters.datum ? "☑" : "☐")).str().data()))}}}}; }, // ⚐ ⚑
                 .edge_to_string_converter = [](auto parameters) -> html_label_t {
                     switch (parameters.accumulated_storage_node_type)
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
                .part_data_to_string_converter_per_part =
                     std::make_tuple([](auto parameters) -> html_label_t { return AUGMENTED_GRAPH_EXAMPLE_PREFIXING(C1001)(parameters); }),
                .iterators_vertex = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex),
                .iterators_edge = AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge),
             }
         ))
    {
        std::vector<std::string> sub_result;
        for (dot::graph_t &graph : graphs)
        {
            sub_result.push_back((std::ostringstream() << graph).str());
        }
        result.push_back(sub_result);
    }
    return result;
}
