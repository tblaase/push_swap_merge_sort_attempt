# push_swap_merge_sort_attempt
This is a attempt to solve the push_swap project of 42 school. The sorting algorithm is based on Merge sort.<br>
**READ THE DISCLAIMER!**<br>
## ---------- DISCLAIMER ----------
<br>
This code is **NOT** a valid solution for the project.<br>
This is just an attempt.<br>

---

This is a merge sort working on 2 stacks.<br>
This code is in a WIP-state.<br>
This code is partly very hard to read because i couldn't make it work good enough for the projects requirements.<br>
For 100 random numbers this algorithm needs roughly 1400-1600 actions. Requirement is less than 1300 actions.<br>
For 500 random numbers this algorithm needs roughly 10500 actions. Requirement is less than 11500 actions.<br>
If you want to see the satisfying sorting run it with a visualizer:<br>
I always used [this](https://github.com/o-reo/push_swap_visualizer "github.com/o-reo/push_swap_visualizer") visualizer.<br>
The checker that you can see in my files, is the cecker suppliedd by 42.<br>

---

There will be quite some errors in the code, caused by the lack of testing it enough.<br>
The Code you might find inside the Libft-folder, is awfull, since alot of the functions are still from the first time i started coding.<br>
But the main algorithm works mostly.<br>
## How to use the algorithm
<br>
Since i didn't finish the project, the Makefile still WIP.<br>
<br>
Compile with:<br>

```
gcc *.c actions/*.c libft/*.c -o push_swap
```

Run it with:<br>

```
./push_swap 3 5 20 17 19 9 15 12 13 11 7 16 10 14 18 2 1 8 4 6
```

Or if you have the visualizer i used:<br>

```
python3 pyviz.py `ruby -e "puts (1..20).to_a.shuffle.join(' ')"`
```

<br>
This is an example of my code working with 50 numbers.<br>
<img src="images/example.gif" >
