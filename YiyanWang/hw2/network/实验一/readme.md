## UDP
![](https://github.com/sjtu-course/homework/blob/main/YiyanWang/hw2/network/%E5%AE%9E%E9%AA%8C%E4%B8%80/image/pic0.png)
服务器监听端口8080， 客户端向服务器发送消息，之后服务器回消息。  

![](https://github.com/sjtu-course/homework/blob/main/YiyanWang/hw2/network/%E5%AE%9E%E9%AA%8C%E4%B8%80/image/pic1.PNG)
![](https://github.com/sjtu-course/homework/blob/main/YiyanWang/hw2/network/%E5%AE%9E%E9%AA%8C%E4%B8%80/image/pic2.PNG)
![](https://github.com/sjtu-course/homework/blob/main/YiyanWang/hw2/network/%E5%AE%9E%E9%AA%8C%E4%B8%80/image/pic3.PNG)

图中可以看到： 客户端向服务器发送 "Hello world!" 服务器回复"nice to see u"
![](https://github.com/sjtu-course/homework/blob/main/YiyanWang/hw2/network/%E5%AE%9E%E9%AA%8C%E4%B8%80/image/pic4.PNG)
![](https://github.com/sjtu-course/homework/blob/main/YiyanWang/hw2/network/%E5%AE%9E%E9%AA%8C%E4%B8%80/image/pic5.PNG)

UDP只能提供不可靠交付。在发送数据之前，不需要建立连接。不需要维持复杂的连接状态表。首部开销只有8字节。网络出现拥塞不会使源主机的发送速率降低，这对实时应用十分重要。