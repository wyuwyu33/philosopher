#include <stdio.h>
#include <pthread.h>

void *func_thread(void *arg)
{
	if (arg)
		return (NULL);
	printf("hello world\n");
	while (1);
	return (NULL);
}

int main()
{
	pthread_t thread;

	// pthread_mutex_init(&thread, NULL);
	// pthread_create(&thread, NULL, func_thread, NULL);
	pthread_detach(thread);
	// pthread_join(thread, NULL);
	// printf("%d\n", pthread_mutex_unlock(&thread));
	// pthread_mutex_destroy(&thread);
	return (0);
}