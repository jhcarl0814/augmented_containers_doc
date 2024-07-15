# augmented_containers_doc

## local development

- server: `cd C:/Users/jhcar/Documents/GitHub/augmented_containers_doc ; python server.py ;`
- tailwindcss watch changes and update `app.css`: `cd C:/Users/jhcar/Documents/GitHub/augmented_containers_doc ; "tailwindcss/tailwindcss-windows-x64.exe" -i input.css -o docs/app.css --watch ;`
- compile (Debug):
  ```bash
  cd C:/cpp/windows/emsdk ;
  ./emsdk install tot ;
  ./emsdk activate tot ;
  source ./emsdk_env.sh ;
  cd C:/Users/jhcar/Documents/GitHub ;
  # configure
  emcmake cmake -S ./augmented_containers_doc -B ./augmented_containers_doc_build -DCMAKE_BUILD_TYPE:STRING=Debug -G 'Ninja' -DCMAKE_MAKE_PROGRAM:FILEPATH='C:/Program Files/ninja/ninja.exe' --fresh --log-context --log-level=STATUS -DFETCHCONTENT_BASE_DIR:PATH='../augmented_containers_doc_dependencies' -DFETCHCONTENT_SOURCE_DIR_BOOST:STRING='C:\cpp\boost_1_84_0\boost' -DFETCHCONTENT_SOURCE_DIR_EXT:PATH='C:\Users\jhcar\Documents\GitHub\ext' -DFETCHCONTENT_SOURCE_DIR_AUGMENTED_CONTAINERS:PATH='C:\Users\jhcar\Documents\GitHub\augmented_containers'
  # build
  cmake                                  --build ./augmented_containers_doc_build                  --config Debug --verbose --clean-first --target augmented_containers_doc_augmented_deque augmented_containers_doc_augmented_deque_copy
  cmake                                  --build ./augmented_containers_doc_build                  --config Debug --verbose --clean-first --target augmented_containers_doc_augmented_sequence augmented_containers_doc_augmented_sequence_copy
  cmake                                  --build ./augmented_containers_doc_build                  --config Debug --verbose --clean-first --target augmented_containers_doc_augmented_graph augmented_containers_doc_augmented_graph_copy
  cmake                                  --build ./augmented_containers_doc_build                  --config Debug --verbose --clean-first
  ```

## publish

- compile (Release):
  ```bash
  cd C:/cpp/windows/emsdk ;
  ./emsdk install tot ;
  ./emsdk activate tot ;
  source ./emsdk_env.sh ;
  cd C:/Users/jhcar/Documents/GitHub ;
  # configure
  emcmake cmake -S ./augmented_containers_doc -B ./augmented_containers_doc_build -DCMAKE_BUILD_TYPE:STRING=Release -G 'Ninja' -DCMAKE_MAKE_PROGRAM:FILEPATH='C:/Program Files/ninja/ninja.exe' --fresh --log-context --log-level=STATUS -DFETCHCONTENT_BASE_DIR:PATH='../augmented_containers_doc_dependencies' -DFETCHCONTENT_SOURCE_DIR_BOOST:STRING='C:\cpp\boost_1_84_0\boost' -DFETCHCONTENT_SOURCE_DIR_EXT:PATH='C:\Users\jhcar\Documents\GitHub\ext' -DFETCHCONTENT_SOURCE_DIR_AUGMENTED_CONTAINERS:PATH='C:\Users\jhcar\Documents\GitHub\augmented_containers'
  # build
  cmake                                  --build ./augmented_containers_doc_build                  --config Release --verbose --clean-first --target augmented_containers_doc_augmented_deque augmented_containers_doc_augmented_deque_copy
  cmake                                  --build ./augmented_containers_doc_build                  --config Release --verbose --clean-first --target augmented_containers_doc_augmented_sequence augmented_containers_doc_augmented_sequence_copy
  cmake                                  --build ./augmented_containers_doc_build                  --config Release --verbose --clean-first --target augmented_containers_doc_augmented_graph augmented_containers_doc_augmented_graph_copy
  cmake                                  --build ./augmented_containers_doc_build                  --config Release --verbose --clean-first
  ```
