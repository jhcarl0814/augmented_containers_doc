
#ifndef AUGMENTED_SEQUENCE_EXAMPLE_PREFIX
    #define AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(id) id
#endif

#include <augmented_containers/augmented_rb2p.hpp>
#include <augmented_containers_doc/augmented_rb2p_visualization.hpp>
#include <augmented_containers/augmented_rb3p.hpp>
#include <augmented_containers_doc/augmented_rb3p_visualization.hpp>
#include <random>

std::random_device AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(rd); // Will be used to obtain a seed for the random number engine
std::mt19937 AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(gen)(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(rd)()); // Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(distrib)(0, 100);

std::vector<augmented_containers::augmented_sequence_t<
    int,
    std::allocator<int>,
    augmented_containers::augmented_sequence_helpers::accumulator_wrapping_accumulating_binary_functor_t<augmented_containers::augmented_sequence_helpers::accumulating_binary_functor_wrapping_homogeneous_binary_functor_t<int, augmented_containers::augmented_sequence_helpers::max_t<int>>>,
    std::integral_constant<augmented_containers::augmented_sequence_physical_representation_e, augmented_containers::augmented_sequence_physical_representation_e::AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION>,
    std::integral_constant<augmented_containers::augmented_sequence_size_management_e, augmented_containers::augmented_sequence_size_management_e::AUGMENTED_SEQUENCE_SIZE_MANAGEMENT> //
    > //
    >
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)(2);
std::vector<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators){
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].begin(),
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].end(),
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].begin(),
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].end(),
};
std::vector<std::size_t> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index){
    0,
    0,
    1,
    1,
};
std::vector<std::size_t> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(get_iterators_container_index)() { return AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index); }
std::vector<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output);
std::size_t AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output_container_index) = 0;
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_decrement)(std::size_t iterator_index) { --AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; }
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_increment)(std::size_t iterator_index) { ++AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; }
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_advance)(std::size_t iterator_index, std::ptrdiff_t offset)
{
    [&](auto &augmented_sequence_iterators) // https://stackoverflow.com/questions/47000914/false-branch-of-if-constexpr-not-discarded-in-templated-lambda
    {
        if constexpr(decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t::support_random_access)
            augmented_sequence_iterators[iterator_index] += offset;
    }(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators));
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_set_index)(std::size_t iterator_index, std::size_t container_index, std::ptrdiff_t index)
{
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)
    [iterator_index] = std::ranges::next(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[container_index].begin(), index);
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
    [iterator_index] = container_index;
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_insert)(std::size_t iterator_index)
{
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)
    [iterator_index] = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index]].insert(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index], AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(distrib)(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(gen)));
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_erase)(std::size_t iterator_index)
{
    if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index]].end())
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_will_be_invalidated;
        std::ranges::transform(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators), std::back_inserter(iterators_will_be_invalidated), [&](decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator)
            { return iterator == AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; });
        std::vector<bool> iterators_output_will_be_invalidated;
        std::ranges::transform(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output), std::back_inserter(iterators_output_will_be_invalidated), [&](decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator)
            { return iterator == AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; });
#else
        std::vector<bool> iterators_will_be_invalidated = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators) | std::views::transform([&](decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator)
                                                                                                                                   { return iterator == AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; }) |
            std::ranges::to<std::vector>();
        std::std::vector<bool> iterators_output_will_be_invalidated = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output) | std::views::transform([&](decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator)
                                                                                                                                                      { return iterator == AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]; }) |
            std::ranges::to<std::vector>();
#endif
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)
        [iterator_index] = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index]].erase(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]);
        std::ranges::for_each(iterators_will_be_invalidated, [&, index = 0](bool iterator_will_be_invalidated) mutable
            {if(iterator_will_be_invalidated)AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[index]=AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index];++index; });
        std::ranges::for_each(iterators_output_will_be_invalidated, [&, index = 0](bool iterator_output_will_be_invalidated) mutable
            {if(iterator_output_will_be_invalidated)AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output)[index]=AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index];++index; });
    }
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_split)(std::size_t iterator_index)
{
    decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::iterator_t iterator_temp = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index];
    if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 0)
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_will_be_invalidated;
        std::ranges::transform(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index), std::back_inserter(iterators_will_be_invalidated), [&](std::size_t iterator_container_index)
            { return iterator_container_index == 1; });
#else
        std::vector<bool> iterators_will_be_invalidated = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index) | std::views::transform([&](std::size_t iterator_container_index)
                                                                                                                                                   { return iterator_container_index == 1; }) |
            std::ranges::to<std::vector>();
#endif
        while(iterator_temp != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].end())
        {
            for(std::size_t other_iterator_index : std::views::iota(static_cast<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators))::size_type>(0), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size()))
            {
                if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[other_iterator_index] == iterator_temp)
                    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
                [other_iterator_index] = 1;
            }
            ++iterator_temp;
        }
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
        [1] = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].split_emit_right(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]);
        std::ranges::for_each(iterators_will_be_invalidated, [&, index = 0](bool iterator_will_be_invalidated) mutable
            {if(iterator_will_be_invalidated)AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[index]=AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].end();++index; });
        if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output_container_index) == 1)
            AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output).clear();
    }
    else if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 1)
    {
#ifdef __EMSCRIPTEN__
        std::vector<bool> iterators_will_be_invalidated;
        std::ranges::transform(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index), std::back_inserter(iterators_will_be_invalidated), [&](std::size_t iterator_container_index)
            { return iterator_container_index == 0; });
#else
        std::vector<bool> iterators_will_be_invalidated = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index) | std::views::transform([&](std::size_t iterator_container_index)
                                                                                                                                                   { return iterator_container_index == 0; }) |
            std::ranges::to<std::vector>();
#endif
        if(iterator_temp != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].begin())
        {
            --iterator_temp;
            while(iterator_temp != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].begin())
            {
                for(std::size_t other_iterator_index : std::views::iota(static_cast<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators))::size_type>(0), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size()))
                {
                    if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[other_iterator_index] == iterator_temp)
                        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
                    [other_iterator_index] = 0;
                }
                --iterator_temp;
            }
            for(std::size_t other_iterator_index : std::views::iota(static_cast<decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators))::size_type>(0), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size()))
            {
                if(other_iterator_index != iterator_index && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[other_iterator_index] == iterator_temp)
                    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
                [other_iterator_index] = 0;
            }
        }
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
        [0] = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].split_emit_left(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index]);
        std::ranges::for_each(iterators_will_be_invalidated, [&, index = 0](bool iterator_will_be_invalidated) mutable
            {if(iterator_will_be_invalidated)AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[index]=AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].end();++index; });
        if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output_container_index) == 0)
            AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output).clear();
    }
    else std::unreachable();
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(concat)(std::size_t container_index)
{
    if(container_index == 0)
    {
        for(std::size_t iterator_index = 0; iterator_index != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size(); ++iterator_index)
        {
            if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 1 && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1].end())
                AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
            [iterator_index] = 0;
        }
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
        [0] << std::move(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1]);
    }
    else if(container_index == 1)
    {
        for(std::size_t iterator_index = 0; iterator_index != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators).size(); ++iterator_index)
        {
            if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index] == 0 && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0].end())
                AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)
            [iterator_index] = 1;
        }
        std::move(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[0]) >> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[1];
    }
    else std::unreachable();
}

void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(iterator_output)(std::size_t iterator_index, std::string value)
{
    if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] != AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[iterator_index]].end())
        *AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[iterator_index] = [&value]()
        { int value_int; std::istringstream(value) >> value_int; return value_int; }();
}
void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(update_range)(std::size_t container_index)
{
    if(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[2 * container_index + 0] == container_index && AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index)[2 * container_index + 1] == container_index &&
        std::ranges::distance(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[container_index].begin(), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 0]) <= std::ranges::distance(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)[container_index].begin(), AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 1]))
        AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
    [container_index].update_range(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 0], AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators)[2 * container_index + 1]);
}

void AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(find_by_heap_predicate)(std::size_t container_index, std::string value)
{
    int value_int;
    std::istringstream(value) >> value_int;
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output).clear();
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s)
    [container_index].find_by_heap_predicate(std::back_inserter(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output)), [&](decltype(AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s))::value_type::accumulated_storage_t const &element_or_max_element_in_tree)
        { return static_cast<int>(element_or_max_element_in_tree) >= value_int; });
    AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output_container_index) = container_index;
}

std::vector<std::string> AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(to_graphs_string)()
{
    std::vector<std::string> result;
    using namespace dot;
    using namespace augmented_containers::detail::visualization::AUGMENTED_SEQUENCE_PHYSICAL_REPRESENTATION_POSTFIXING(augmented_sequence_);
    for(dot::graph_t &graph : to_graphs(
            AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_s),
            to_graphs_parameters_t{
                .element_to_string_converter = [](auto parameters) -> html_label_t
                { return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << parameters.datum).str().data()))}}}}; },
               .accumulated_storage_to_string_converter = [](auto parameters) -> html_label_t
                { return html_label_t{text_t{{{std::u8string(reinterpret_cast<char8_t const *>((std::ostringstream() << parameters.datum).str().data()))}}}}; },
               .iterators = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators),
               .iterators_container_index = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_container_index),
               .read_range = true,
               .iterators_output = AUGMENTED_SEQUENCE_EXAMPLE_PREFIXING(augmented_sequence_iterators_output),
            }))
    {
        result.push_back((std::ostringstream() << graph).str());
    }
    return result;
}
