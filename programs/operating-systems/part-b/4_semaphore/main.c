#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>   // set_t
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty, full, mutex;

void* producer(void* arg) {

    for(int i = 1; i <= 10; i++) {
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;
        printf("Producer produced: %d\n", i);

        sem_post(&mutex);
        sem_post(&full);

        sleep(1);
    }

    return NULL;
}

void* consumer(void* arg) {

    for (int i = 1; i <= 10; i++) {
        sem_wait(&full);
        sem_wait(&mutex);

        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumer consumed: %d\n", item);

        sem_post(&mutex);
        sem_post(&empty);

        sleep(2);
    }

    return NULL;
}

int main() {
    pthread_t producer_thread;
    pthread_t consumer_thread;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
