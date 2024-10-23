# 数据库方向面试题  
## 241012 收集面试题 
### 自我介绍  
### 项目介绍 
* 项目中需要提到分布式协议采用了jraft协议，为什么选择jraft？ 
答：核心原因是我们内部大量实现是基于java语言的，所以在选择的框架的时候采用了jraft, 并且jraft本身是阿里开源的分布式协议，在阿里内部使用了很多年，经过了大规模的测试和验证。(明天在问一下)  * IPC进程间通信（socket）  
### 面试题 ：
#### raft 
介绍一下raft算法 
答：1、raft算法是一种分布式一致性算法，主要解决分布式中数据的一致性问题。其核心是通过leader选举、日志复制、安全性和日志压缩等机制进行保证的。Raft 是一种 Leader-Based 的 Multi-Paxos 变种，集群中的相关决策都需要leader进行处理，相对paxo，raft的其实现更新详细（比如节点变更）、而且更容易理解，相对的工程化实现更多。  它有三个组成部分第一个leader（接受客户端请求，并向Follower同步请求日志，当日志同步到大多数节点上后告诉Follower提交日志。）、cancadidata（候选者）：即follower状态要进行变更为leader的中间状态，主要leader选举过程。第三个是follower（跟随着）：接受并持久化Leader同步的日志，在Leader告之日志可以提交之后，提交日志。    
4. read index&amp;read lease read Index 这是raft论文提到的一个优化。核心就是通过heatbeat readIndex 大于 applyIndex，就可以保证正常的读操作。而不将读操作采用类似写操作的流程，从而减少IO和消息通信代价。  
5. raft - preVote 解决情况： 减少leader election 过程  

#### 存储

*  存储引擎
  * LSM-Tree
    * leveldb
      1. leveldb&amp;rocksdb 
      2. leveldb读请求优化 
      3. leveldb迭代器实现 
      4. leveldb compaction 
      5. etcd&amp;zookeeper 
      6. 哈希冲突 
    * rocksdb
  * B+树
  * Hash存储

#### 缓存

#### 查询语言

#### 索引

#### 事务


#### 代码题

* 数组
  *Two Sum
  *Best Time to Buy and Sell Stock
  *Container With Most Water

* 链表 (状态：👌) 
  * Reverse Linked List (状态：👌) 链接： https://leetcode.cn/problems/reverse-linked-list/description/
  * Merge Two Sorted Lists (状态：👌)  链接： https://leetcode.cn/problems/merge-two-sorted-lists/ 
  * Remove Nth Node From End of List   链接：
  * Merge k Sorted Lists (状态：👌)  链接： https://leetcode.cn/problems/merge-k-sorted-lists/


#### 反问


### database
#### mysql
* 问：什么是覆盖索引
  答：覆盖索引是mysql的一种减少回表查询的优化方式。即通过遍历b+树就可以获取查询的字段，而不需要在通过回表进行查询，减少查询的成本，加快速度。对查询字段建立“普通索引”和“联合索引”，这样就不用通过聚集索引在去定位，避免回表

* 问：什么是回表查询
  答: 回表指索引无法直接获取所需数据，需要通过聚集索引再次查询，获取最终需要查询的数据记录，通过聚集索引再次查询的过程就是回表操作，这个过程会增加IO开销影响性能，所以mysql采用了“覆盖索引”这个优化测试。

* 问：介绍mysql中事务的特性

* 问: 介绍mvcc内部的实现细节
  答：

* 问：MySQL 的可重复读怎么实现的
  答：

* 问：Repeatable Read 解决了幻读问题吗
  答：

* 问：请说⼀下数据库锁的种类
  答：锁的种类可用从不同的维度进行分类。
  从操作类型可以分为：共享锁和排它锁，共享锁主要是针对读操作的，用户进行select操作时候采用的便是共享锁，用户在进行delete、update、insert操作是需要获取排它锁。共享锁和共享锁不存在冲突，但是排它锁和共享锁以及其他排它锁之间存在冲突；
  从性能维度可以分为悲观锁和乐观锁，乐观锁即任务任务冲突概率很低，所以采用不加锁，而是采用版本比较的方式，检测冲突情况，冲突就提示错误；悲观锁即事务存在大量争抢，所以采用的策略是对操作加锁，即会锁定操作对象，防止其他修改；共享锁和排它锁属于悲观锁的不同实现，都属于悲观锁。
  从对象维度可以分为：表锁、行锁、Page锁，表锁顾名思义直接是锁住整个表，其不会出现死锁，但是由于锁的颗粒大，冲突概率大，性能较差。行锁锁的便是一行记录，即recored lock，这是数据库层面最小的锁粒度，存在死锁情况，冲突概率低，并发高。page锁的颗粒度介于行锁和表锁之间。
  问：行锁的死锁情况？？

* 问：请说⼀下共享锁和排他锁
  答：在行锁下有两种锁，即共享锁和排它锁，使用MySQL⾏级锁的两个前提，使⽤ innoDB 和 引擎开启事务 (隔离级别为 Repeatable Read )。
  共享锁（读锁）：主要针对数据库的读操作，获取共享锁不会阻塞其他事务的读操作，但是要获取排它锁也就是写操作，需要等他所有共享锁释放；加锁方式 lock in share mode 
  排它锁（写锁）：用户进行增删改操作会获取排它锁，排它锁与其他的锁都互斥，其他事务如果要获取这个锁，需要等待其锁释放。加锁方式  for update

* 问：InnoDB 的⾏锁是怎么实现的

* 问：并发事务会产⽣哪些问题

* 问：说⼀下MVCC内部细节


* 问：