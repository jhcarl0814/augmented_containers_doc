# augmented_containers_doc

## local development

- server: `cd C:/Users/jhcar/Documents/GitHub/augmented_containers_doc && python server.py`
- tailwindcss watch changes and update `app.css`: `cd C:/Users/jhcar/Documents/GitHub/augmented_containers_doc && "tailwindcss/tailwindcss-windows-x64.exe" -i input.css -o docs/app.css --watch`
- compile ([how to write multiline commands on windows](https://stackoverflow.com/a/72988250)):
  ```winbatch
  cd C:/cpp/windows/emsdk && ^
    emsdk activate tot && ^
    cd C:/Users/jhcar/Documents/GitHub/augmented_containers_doc && ^
    em++ -std=c++2b -O3 -IC:/Users/jhcar/Documents/GitHub/augmented_containers -IC:/Users/jhcar/Documents/GitHub/augmented_containers_doc -IC:/cpp/ext -lembind -o docs/augmented_deque.html augmented_deque_template.cpp --shell-file augmented_deque_template.html -s NO_EXIT_RUNTIME=1 -s USE_BOOST_HEADERS=1 -sALLOW_MEMORY_GROWTH -sASSERTIONS -s TOTAL_MEMORY=64MB -s TOTAL_STACK=1MB -sSINGLE_FILE -s MINIFY_HTML=0 -sNO_DISABLE_EXCEPTION_CATCHING
  ```
  ```winbatch
  cd C:/cpp/windows/emsdk && ^
    emsdk activate tot && ^
    cd C:/Users/jhcar/Documents/GitHub/augmented_containers_doc && ^
    em++ -std=c++2b -O3 -IC:/Users/jhcar/Desktop/augmented_containers/augmented_containers -IC:/cpp/ext -lembind -o docs/augmented_deque.html augmented_deque_template.cpp --shell-file augmented_deque_template.html -s NO_EXIT_RUNTIME=1 -s USE_BOOST_HEADERS=1 -sALLOW_MEMORY_GROWTH -sASSERTIONS -s TOTAL_MEMORY=64MB -s TOTAL_STACK=1MB -sSINGLE_FILE -s MINIFY_HTML=0 -sNO_DISABLE_EXCEPTION_CATCHING
  ```
