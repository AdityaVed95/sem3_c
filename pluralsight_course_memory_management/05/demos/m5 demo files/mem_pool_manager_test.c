#include <stdio.h>
#include <stdlib.h>
#include "mem_pool_manager.h"

typedef struct TestMetrics {
    int pour_mode;
    int pour_duration;
    float flow;
    double heat;
} TestMetrics;

int send_metrics(TestMetrics*);

int main() {
    int needed_metric_objects = 100000000;
    for(int i = 0; i < needed_metric_objects; i++) {
        TestMetrics *metrics = (TestMetrics*)malloc(sizeof(TestMetrics));
        send_metrics(metrics);
    }
    
    return 0;
}

int send_metrics(TestMetrics *metrics) {
    // Simulate some metrics processing here
    free(metrics);
    return 0;
}
