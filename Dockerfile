# Используем официальный образ с CMake и поддержкой C++
FROM ubuntu:22.04

# Устанавливаем необходимые пакеты
RUN apt-get update && \
    apt-get install -y cmake g++ wget

# Копируем файлы проекта в контейнер
WORKDIR /app
COPY . .

# Сборка проекта
RUN cmake . && make

# Открываем порт 80
EXPOSE 80

# Запускаем приложение
CMD ["./my_httplib_app"]
