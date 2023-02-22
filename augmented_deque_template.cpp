
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>

#include "augmented_deque.hpp"
#include "augmented_deque_visualization.hpp"
#include <ranges>

#include<random>
#include "ext_infrastructure/ext_utility.hpp"

#define AUGMENTED_DEQUE_EXAMPLE_PREFIX empty_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) empty_ ## id
#include "augmented_deque_examples/empty.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX empty_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) empty_interactive_ ## id
#include "augmented_deque_examples/empty.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX

#define AUGMENTED_DEQUE_EXAMPLE_PREFIX accumulator_only_yield_one_value_string_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) accumulator_only_yield_one_value_string_ ## id
#include "augmented_deque_examples/accumulator_only_yield_one_value_string.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX accumulator_only_yield_one_value_string_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) accumulator_only_yield_one_value_string_interactive_ ## id
#include "augmented_deque_examples/accumulator_only_yield_one_value_string.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX

#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_value_int_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_value_int_ ## id
#include "augmented_deque_examples/projector_and_accumulator_yield_one_value_int.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_value_int_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_value_int_interactive_ ## id
#include "augmented_deque_examples/projector_and_accumulator_yield_one_value_int.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX

#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_value_string_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_value_string_ ## id
#include "augmented_deque_examples/projector_and_accumulator_yield_one_value_string.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_value_string_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_value_string_interactive_ ## id
#include "augmented_deque_examples/projector_and_accumulator_yield_one_value_string.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX

#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_multiple_values_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_multiple_values_ ## id
#include "augmented_deque_examples/projector_and_accumulator_yield_multiple_values.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_multiple_values_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_multiple_values_interactive_ ## id
#include "augmented_deque_examples/projector_and_accumulator_yield_multiple_values.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX

#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_view_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_view_ ## id
#include "augmented_deque_examples/projector_and_accumulator_yield_one_view.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_view_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_view_interactive_ ## id
#include "augmented_deque_examples/projector_and_accumulator_yield_one_view.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX

#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_multiple_views_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_multiple_views_ ## id
#include "augmented_deque_examples/projector_and_accumulator_yield_multiple_views.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_multiple_views_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_multiple_views_interactive_ ## id
#include "augmented_deque_examples/projector_and_accumulator_yield_multiple_views.hpp"
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX

EMSCRIPTEN_BINDINGS(module) {
	
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX empty_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "empty_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) empty_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX empty_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "empty_interactive_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) empty_interactive_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
	
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX accumulator_only_yield_one_value_string_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "accumulator_only_yield_one_value_string_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) accumulator_only_yield_one_value_string_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX accumulator_only_yield_one_value_string_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "accumulator_only_yield_one_value_string_interactive_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) accumulator_only_yield_one_value_string_interactive_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
	
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_value_int_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "projector_and_accumulator_yield_one_value_int_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_value_int_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_value_int_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "projector_and_accumulator_yield_one_value_int_interactive_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_value_int_interactive_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
	
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_value_string_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "projector_and_accumulator_yield_one_value_string_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_value_string_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_value_string_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "projector_and_accumulator_yield_one_value_string_interactive_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_value_string_interactive_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX

#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_multiple_values_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "projector_and_accumulator_yield_multiple_values_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_multiple_values_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_multiple_values_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "projector_and_accumulator_yield_multiple_values_interactive_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_multiple_values_interactive_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX

#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_view_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "projector_and_accumulator_yield_one_view_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_view_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_one_view_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "projector_and_accumulator_yield_one_view_interactive_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_one_view_interactive_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX

#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_multiple_views_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "projector_and_accumulator_yield_multiple_views_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_multiple_views_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));
  
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX
#define AUGMENTED_DEQUE_EXAMPLE_PREFIX projector_and_accumulator_yield_multiple_views_interactive_
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING(str) "projector_and_accumulator_yield_multiple_views_interactive_" str
#define AUGMENTED_DEQUE_EXAMPLE_PREFIXING(id) projector_and_accumulator_yield_multiple_views_interactive_ ## id
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("sequences_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(sequences_count));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterators_element_count"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterators_element_count));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_front"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_front));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("push_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(push_back));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("pop_back"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(pop_back));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_get_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_get_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_set_index"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_set_index));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_increment"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_increment));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_decrement"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_decrement));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_advance"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_advance));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("iterator_element_output"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(iterator_element_output));
  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(update_range));

  emscripten::function(AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_DEQUE_EXAMPLE_PREFIXING(to_graphs_string));
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIXING_STRING
#undef AUGMENTED_DEQUE_EXAMPLE_PREFIX

  emscripten::register_vector<std::string>("vector<string>");
}

int main()
{
	
}
