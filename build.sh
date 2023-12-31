#!/bin/bash

# Build the project
echo "Building the project..."
emcc ./main.c -s "EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']"

# Copy the generated files to the public folder
echo "Copying the generated files to the public folder..."
cp ./index.html ./public/index.html
mv ./a.out.js ./a.out.wasm ./public/
