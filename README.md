# augmented_containers_doc

## local development

- server: `cd C:/Users/jhcar/Documents/GitHub/augmented_containers_doc ; python server.py ;`
- tailwindcss watch changes and update `app.css`: `cd C:/Users/jhcar/Documents/GitHub/augmented_containers_doc ; "tailwindcss/tailwindcss-windows-x64.exe" -i input.css -o docs/app.css --watch ;`
- compile:
  ```bash
  cd C:/cpp/windows/emsdk ;
  ./emsdk install tot ;
  ./emsdk activate tot ;
  source ./emsdk_env.sh ;
  cd C:/Users/jhcar/Documents/GitHub/augmented_containers_doc ;
  em++ -std=c++2b -O3 -IC:/Users/jhcar/Documents/GitHub/augmented_containers/include -IC:/Users/jhcar/Documents/GitHub/augmented_containers_doc -IC:/cpp/ext -lembind -o docs/augmented_deque.html augmented_deque_template.cpp --shell-file augmented_deque_template.html -s NO_EXIT_RUNTIME=1 -s USE_BOOST_HEADERS=1 -sALLOW_MEMORY_GROWTH -sASSERTIONS -s TOTAL_MEMORY=64MB -s TOTAL_STACK=1MB -sSINGLE_FILE -s MINIFY_HTML=0 -sNO_DISABLE_EXCEPTION_CATCHING -Wno-invalid-offsetof -fexperimental-library -Wno-null-dereference ;
  em++ -std=c++2b -O3 -IC:/Users/jhcar/Documents/GitHub/augmented_containers/include -IC:/Users/jhcar/Documents/GitHub/augmented_containers_doc -IC:/cpp/ext -lembind -o docs/augmented_sequence.html augmented_sequence_template.cpp --shell-file augmented_sequence_template.html -s NO_EXIT_RUNTIME=1 -s USE_BOOST_HEADERS=1 -sALLOW_MEMORY_GROWTH -sASSERTIONS -s TOTAL_MEMORY=64MB -s TOTAL_STACK=1MB -sSINGLE_FILE -s MINIFY_HTML=0 -sNO_DISABLE_EXCEPTION_CATCHING -Wno-invalid-offsetof -fexperimental-library -Wno-null-dereference ;
  em++ -std=c++2b -O3 -IC:/Users/jhcar/Documents/GitHub/augmented_containers/include -IC:/Users/jhcar/Documents/GitHub/augmented_containers_doc -IC:/cpp/ext -lembind -o docs/augmented_graph.html augmented_graph_template.cpp --shell-file augmented_graph_template.html -s NO_EXIT_RUNTIME=1 -s USE_BOOST_HEADERS=1 -sALLOW_MEMORY_GROWTH -sASSERTIONS -s TOTAL_MEMORY=64MB -s TOTAL_STACK=1MB -sSINGLE_FILE -s MINIFY_HTML=0 -sNO_DISABLE_EXCEPTION_CATCHING -Wno-invalid-offsetof -fexperimental-library -Wno-null-dereference ;
  ```
