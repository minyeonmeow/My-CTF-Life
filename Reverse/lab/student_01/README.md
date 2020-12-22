你可以加上一些選項讓 gcc 不要使用 pic pie 的格式

`gcc -fno-pic -no-pie  switch_5.c -o switch_5_nopie`

或是把 stack guard 拿掉，比較不影響觀看(從 GS:xx 拿東西出來，並且會 check_stack_fail 的部分就是 stack guard)
此外 -m32 可以編譯成 32bit 的執行檔，才能看到 x86 calling convetion (要 `apt install gcc-multilib`)

`gcc -fno-stack-protector -fno-pic -no-pie -m32 stack.c -o stack`
