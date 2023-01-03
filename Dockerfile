FROM gcc:12.2

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update \
      && apt-get install -y libgtest-dev libboost-test-dev \
      && rm -rf /var/lib/apt/lists/* \
      && wget https://github.com/Kitware/CMake/releases/download/v3.24.3/cmake-3.24.3-Linux-x86_64.sh \
      -q -O /tmp/cmake-install.sh \
      && chmod u+x /tmp/cmake-install.sh \
      && mkdir /usr/bin/cmake \
      && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
      && rm /tmp/cmake-install.sh

ENV PATH="/usr/bin/cmake/bin:${PATH}"

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . .

# Specify the working directory
WORKDIR .

RUN mkdir ./build
RUN cmake -B/build -S . -D CMAKE_BUILD_TYPE=Release
RUN cmake --build /build

RUN echo "Starting..."

CMD ["./build/RunnerServer"]