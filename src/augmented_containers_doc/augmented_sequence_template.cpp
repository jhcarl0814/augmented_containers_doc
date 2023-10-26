
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/empty.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_value.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_values.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_one_view.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/accumulator_yield_multiple_views.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_monotonic_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb2p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb2p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_no_size_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_no_size_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT no_size
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_at_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_at_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_at_each_node_except_node_end_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_at_each_node_except_node_end_interactive_ ## id
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION rb3p
    #define AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(id) id##rb3p
    #define AUGMENTED_SEQUENCE_SIZE_MANAGEMENT at_each_node_except_node_end
    #include <augmented_containers_doc/augmented_sequence_examples/find_by_heap_predicate_generator.hpp>
    #undef AUGMENTED_SEQUENCE_SIZE_MANAGEMENT
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING
    #undef AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif


EMSCRIPTEN_BINDINGS(module) {

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb2p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb2p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb2p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb2p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb2p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb2p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb2p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb3p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb3p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb3p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb3p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb3p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX empty_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "empty_rb3p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) empty_rb3p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb2p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb2p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb2p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb2p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb2p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb2p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb2p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb3p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb3p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb3p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb3p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb3p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_value_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_value_rb3p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_value_rb3p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb2p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb2p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb2p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb2p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb2p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb2p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb2p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb3p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb3p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb3p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb3p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb3p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_values_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_values_rb3p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_values_rb3p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb2p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb2p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb2p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb2p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb2p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb2p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb2p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb3p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb3p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb3p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb3p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb3p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_one_view_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_one_view_rb3p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_one_view_rb3p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb2p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb2p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb2p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb2p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb2p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb2p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb2p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb3p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb3p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb3p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb3p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb3p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX accumulator_yield_multiple_views_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "accumulator_yield_multiple_views_rb3p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) accumulator_yield_multiple_views_rb3p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb2p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb2p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb2p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb2p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb2p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb2p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb2p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb3p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb3p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb3p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb3p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb3p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_monotonic_predicate_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_monotonic_predicate_rb3p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_monotonic_predicate_rb3p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_monotonic_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_monotonic_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb2p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb2p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb2p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb2p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb2p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb2p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb2p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb3p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb3p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb3p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb3p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb3p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_rb3p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_rb3p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

#if 1
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb2p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb2p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb2p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb2p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb2p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb2p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb2p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb2p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_no_size_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb3p_no_size_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_no_size_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_no_size_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb3p_no_size_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_no_size_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_at_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb3p_at_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_at_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_at_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb3p_at_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_at_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX

    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_at_each_node_except_node_end_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb3p_at_each_node_except_node_end_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_at_each_node_except_node_end_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIX find_by_heap_predicate_generator_rb3p_at_each_node_except_node_end_interactive_
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING(str) "find_by_heap_predicate_generator_rb3p_at_each_node_except_node_end_interactive_" str
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) find_by_heap_predicate_generator_rb3p_at_each_node_except_node_end_interactive_ ## id
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("get_iterators_container_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_decrement"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_increment"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_advance"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_set_index"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_insert"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_erase"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_split"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("concat"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("iterator_output"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output));
        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("update_range"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("find_by_heap_predicate_generator"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate_generator));

        emscripten::function(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING("to_graphs_string"), &AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string));
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING_STRING
    #undef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
#endif

  emscripten::register_vector<std::size_t>("vector<size_t>");
  emscripten::register_vector<std::string>("vector<string>");
}

int main()
{
	
}
