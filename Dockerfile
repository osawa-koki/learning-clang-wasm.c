FROM emscripten/emsdk:3.1.47
WORKDIR /src/
COPY ./ ./
RUN emcc ./main.c
RUN cp ./a.out.js ./a.out.wasm ./public/
