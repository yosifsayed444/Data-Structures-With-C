#include <stdio.h>
#include "queue.h"

Queue mergeCodes(Queue sectionCodes, Queue groupCodes) {
    Queue mergedQueue;
    createQueue(&mergedQueue);

    while (!isQueueEmpty(sectionCodes) && !isQueueEmpty(groupCodes)) {
        int sectionCode = dequeue(&sectionCodes);
        int groupCode = dequeue(&groupCodes);

        int mergedCode = sectionCode * 10 + groupCode;

        enqueue(&mergedQueue, mergedCode);
    }

    return mergedQueue;
}

int mainMQ() {
    Queue sectionCodes;
    createQueue(&sectionCodes);
    Queue groupCodes;
    createQueue(&groupCodes);
    enqueue(&sectionCodes, 1);
    enqueue(&sectionCodes, 2);
    enqueue(&sectionCodes, 3);
    enqueue(&groupCodes, 1);
    enqueue(&groupCodes, 2);
    enqueue(&groupCodes, 3);
    Queue mergedQueue = mergeCodes(sectionCodes, groupCodes);
    while (!isQueueEmpty(mergedQueue)) {
        int mergedCode = dequeue(&mergedQueue);
        printf("Merged Code: %d\n", mergedCode);
    }
    return 0;
}
