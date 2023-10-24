FROM emscripten/emsdk:3.1.47
WORKDIR /src/
COPY ./ ./
RUN emcc ./main.c
RUN chmod +x ./build.sh && ./build.sh
