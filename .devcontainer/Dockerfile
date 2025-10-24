# Этап 1 — сборка проекта
FROM ubuntu:24.04 AS builder

# Обновляем систему и ставим зависимости
RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    git \
    make \
    libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

# Собираем GoogleTest вручную (нужно для линковки)
RUN cd /usr/src/googletest && cmake . && make && cp lib/*.a /usr/lib

# Создаем рабочую директорию
WORKDIR /app

# Копируем весь проект в контейнер
COPY . .

# Создаём директорию сборки
RUN mkdir -p build
WORKDIR /app/build

# Конфигурируем и собираем проект
RUN cmake .. && cmake --build .

# Этап 2 — финальный образ (только бинарники)
FROM ubuntu:24.04

# Устанавливаем минимально необходимые зависимости
RUN apt-get update && apt-get install -y libstdc++6 && rm -rf /var/lib/apt/lists/*

# Рабочая директория
WORKDIR /app

# Копируем собранные бинарники из предыдущего этапа
COPY --from=builder /app/build/lab3 /usr/local/bin/lab3
COPY --from=builder /app/build/runTests /usr/local/bin/runTests

# По умолчанию запускать тесты
CMD ["runTests"]
