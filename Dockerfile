FROM emscripten/emsdk:3.1.47
WORKDIR /src/
COPY ./ ./
RUN emcc ./main.c -o ./public/index.html
