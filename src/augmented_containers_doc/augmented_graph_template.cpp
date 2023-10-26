
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX empty_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) empty_ ## id
#include <augmented_containers_doc/augmented_graph_examples/empty.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX empty_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) empty_interactive_ ## id
#include <augmented_containers_doc/augmented_graph_examples/empty.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX arbitrary_spanning_forest_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) arbitrary_spanning_forest_ ## id
#include <augmented_containers_doc/augmented_graph_examples/arbitrary_spanning_forest.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX arbitrary_spanning_forest_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) arbitrary_spanning_forest_interactive_ ## id
#include <augmented_containers_doc/augmented_graph_examples/arbitrary_spanning_forest.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX minimum_spanning_forest_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) minimum_spanning_forest_ ## id
#include <augmented_containers_doc/augmented_graph_examples/minimum_spanning_forest.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX minimum_spanning_forest_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) minimum_spanning_forest_interactive_ ## id
#include <augmented_containers_doc/augmented_graph_examples/minimum_spanning_forest.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX minimum_spanning_forests_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) minimum_spanning_forests_ ## id
#include <augmented_containers_doc/augmented_graph_examples/minimum_spanning_forests.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX minimum_spanning_forests_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) minimum_spanning_forests_interactive_ ## id
#include <augmented_containers_doc/augmented_graph_examples/minimum_spanning_forests.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_nearest_marked_vertexes_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_nearest_marked_vertexes_ ## id
#include <augmented_containers_doc/augmented_graph_examples/tree_nearest_marked_vertexes.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_nearest_marked_vertexes_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_nearest_marked_vertexes_interactive_ ## id
#include <augmented_containers_doc/augmented_graph_examples/tree_nearest_marked_vertexes.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_diameter_and_centers_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_diameter_and_centers_ ## id
#include <augmented_containers_doc/augmented_graph_examples/tree_diameter_and_centers.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_diameter_and_centers_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_diameter_and_centers_interactive_ ## id
#include <augmented_containers_doc/augmented_graph_examples/tree_diameter_and_centers.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_medians_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_medians_ ## id
#include <augmented_containers_doc/augmented_graph_examples/tree_medians.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_medians_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_medians_interactive_ ## id
#include <augmented_containers_doc/augmented_graph_examples/tree_medians.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_jump_and_meet_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_jump_and_meet_ ## id
#include <augmented_containers_doc/augmented_graph_examples/tree_jump_and_meet.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_jump_and_meet_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_jump_and_meet_interactive_ ## id
#include <augmented_containers_doc/augmented_graph_examples/tree_jump_and_meet.hpp>
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

EMSCRIPTEN_BINDINGS(module) {

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX empty_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "empty_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) empty_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX empty_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "empty_interactive_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) empty_interactive_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX arbitrary_spanning_forest_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "arbitrary_spanning_forest_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) arbitrary_spanning_forest_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX arbitrary_spanning_forest_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "arbitrary_spanning_forest_interactive_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) arbitrary_spanning_forest_interactive_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX minimum_spanning_forest_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "minimum_spanning_forest_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) minimum_spanning_forest_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX minimum_spanning_forest_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "minimum_spanning_forest_interactive_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) minimum_spanning_forest_interactive_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX minimum_spanning_forests_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "minimum_spanning_forests_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) minimum_spanning_forests_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX minimum_spanning_forests_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "minimum_spanning_forests_interactive_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) minimum_spanning_forests_interactive_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_nearest_marked_vertexes_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "tree_nearest_marked_vertexes_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_nearest_marked_vertexes_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_disconnected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_disconnected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_nearest_marked_vertexes_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "tree_nearest_marked_vertexes_interactive_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_nearest_marked_vertexes_interactive_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_disconnected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_disconnected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_diameter_and_centers_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "tree_diameter_and_centers_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_diameter_and_centers_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_disconnected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_disconnected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_non_local_search"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_non_local_search));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_diameter_and_centers_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "tree_diameter_and_centers_interactive_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_diameter_and_centers_interactive_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_disconnected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_disconnected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_non_local_search"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_non_local_search));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_medians_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "tree_medians_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_medians_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_disconnected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_disconnected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_non_local_search"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_non_local_search));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_medians_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "tree_medians_interactive_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_medians_interactive_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_disconnected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_disconnected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_non_local_search"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_non_local_search));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_jump_and_meet_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "tree_jump_and_meet_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_jump_and_meet_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_disconnected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_disconnected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_search_jump"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_search_jump));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_search_meet"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_search_meet));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX
#define AUGMENTED_GRAPH_EXAMPLE_PREFIX tree_jump_and_meet_interactive_
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING(str) "tree_jump_and_meet_interactive_" str
#define AUGMENTED_GRAPH_EXAMPLE_PREFIXING(id) tree_jump_and_meet_interactive_ ## id
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_vertex"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_vertex));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("size_edge"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(size_edge));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_vertex_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_vertex_count));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterators_edge_count"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterators_edge_count));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_erase));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_disconnected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_disconnected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_is_connected"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_is_connected));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_decrement"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_decrement));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_increment"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_increment));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_set_index"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_set_index));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_insert"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_insert));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_erase"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_erase));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_update"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_update));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_unexpose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertex_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertex_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_edge_expose_replace"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_edge_expose_replace));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("unexpose"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(unexpose));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_search_jump"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_search_jump));
    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("iterator_vertexes_search_meet"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(iterator_vertexes_search_meet));

    emscripten::function(AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_GRAPH_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_GRAPH_EXAMPLE_PREFIX

  emscripten::register_vector<std::string>("vector<string>");
  emscripten::register_vector<std::vector<std::string>>("vector<vector<string>>");
}

int main()
{
	
}
