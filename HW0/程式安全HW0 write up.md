# 程式安全HW0 write up

###### tags: `CTF` `write up` `程式安全`

### Web<br/>
- 進去之後發現"I am cute"不能點選<br/>
![](https://i.imgur.com/KlOgofP.png)<br/>
    - F12查看source<br/>
    ![](https://i.imgur.com/3LwVDjc.png)<br/>
    - 把disable改成checked即可<br/>
    ![](https://i.imgur.com/vwpGBxN.png)<br/>

### Pwn<br/>
- 先執行一次,刻意輸入很長的字串 : segmentation fault代表有buffer overflow漏洞<br/>
    ![](https://i.imgur.com/lU59Zks.png)<br/>
- 原因是因為scanf("%s", buffer)沒有加以限制讀取長度,若buffer設置在stack上,就能夠往下蓋到return address的位置<br/>
    - 由dump出的assembly知道<br/>
    ![](https://i.imgur.com/unjoMr9.png)<br/>
        * main+115 : 只需要 0x10 + 0x8(old_rbp) + 0x8(ret_addr)就可以達成bof蓋到return address<br/>
- objdump之後發現text段上還有一個func1()<br/>
    ![](https://i.imgur.com/soZg4vM.png)<br/>
    - input如果前8byte為0xcafecafecafecafe,就會執行system('/bin/sh'),如果不相等就執行exit<br/>
- 透過bof將return address蓋成執行system('/bin/sh')的地方,這樣ret = pop rip,就可以將rip設為執行system()<br/>
    - 之所以不直接跳到func1頭是因為system要求stack要0x10對齊<br/>
      如果是正常call function, 在call時會push rip,此時func1一開始執行push rbp就能夠對齊<br/>
      但這邊我們利用ret來跳到這個func1,少掉了這個push rip,call system時,rsp=0x...8,沒有0x10對齊,因此system()無法成功執行<br/>
      因此只要避開"push rbp"這個指令即可(ret到第二行以後)<br/>
      
- exploit<br/>
![](https://i.imgur.com/nZDvDkf.png)<br/>
    
### MISC<br/>
> 感覺應該是浮點數overflow的漏洞(?<br/>

### Crypto<br/>

### Reverse<br/>

