import heapq

def merged_lists(lists):
    merged = list()
    heap = [(el[0], i, 0) for i, el in enumerate(lists) if el]
    heapq.heapify(heap)
    
    while heap:
        val, list_id, el_id = heapq.heappop(heap)
        
        merged.append(val)

        if el_id + 1 < len(lists[list_id]):
            next_tuple = (lists[list_id][el_id+1], list_id, el_id+1)
            heapq.heappush(heap, next_tuple)
    
    return merged

def main():
    lists = [[1, 4, 5],[3, 7, 8],[2, 6, 9]]
    merged = merged_lists(lists)
    print('Lista: ', merged)

main()
