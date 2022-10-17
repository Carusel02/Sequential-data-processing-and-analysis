# Sequential data processing and analysis
## Solution method
`main functions`
- as main functions I used adding to the list, deleting
to a node in the list, copying a list to another list, displaying
of a list, freeing the nodes of a list

`task1` (e1)
- the main idea underlying the requirement was the use
a "flag" to mark the nodes to be deleted.
- thus, the list will be scanned once more and they will be deleted
the nodes that have an active flag(1).(could also be used
and changing the timestamp with a negative value for a
highlight this procedure)
- also, I implemented 2 functions that calculate the deviation and
mediate.

`task2` (e2)
- for task2, a simple way to solve it would be to add the window of
5 nodes in an auxiliary list, then sorting it.
- the value in the middle is then added, and for chaining
orders, I had to give free to the previous list and it
update with the new list formed from these extracted values.

`task3` (e3)
- similar to task2, it needed a function thatcalculate the average on a window of 5 nodes and add it to a the new list.
- at the end, the old list is updated.

`task4` (u)
- the equalization of the frequency consisted of a simple operation which
go through the list and modify the nodes that meet the requirements.
- using a smoothing function, I modified the list accordingly
requirement.

`task5` (c)
- completing an interval consists of adding elements after
a knot.
- the timestamp of the node changes by +200 to the last value
and the date of each node is influenced by a parameter C.
- the left and right sums are weighted averages (constant numbers
for an interval in which nodes are added) that take into account
the first 3 terms and the last 3 terms from where the addition is made.
- they are multiplied by some coefficients, the most important (large)
coefficients being multiplied by the terms closest to
the interval in which it is added.
- for this task, I used a single function that calculates
each information of a node and adds it after a node through a
auxiliary function.

`task6` (st)
- the part with the extract from the argument was made using operations with
the ASCII code, then this number was passed as a parameter
in a function that sorts and then counts how many nodes the data has
belonging to the interval.

## Implementation
- to implement the code, I used VScode on Linux
to be able to use the utility valgrind (for memory leaks) and gdb
(for segmentation faults).
- *the hardest part wasn't the requirement
and writing the code, but the debugging part xD*
