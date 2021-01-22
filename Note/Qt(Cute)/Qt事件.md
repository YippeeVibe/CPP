人机交互事件可以总结为：鼠标事件，键盘事件，touch事件。

在Qt中关于事件的描述可以参考 文档 bool QApplication::notify(QObject*,QEvent*)。
这里有一些经验。
1. 重载notify是最powerful的，一个应用程序的所有事件都经此。另一方面是，当深入底层时，要考虑的事情也会变多，不推荐使用。
   麻烦事情：在一个应用程序中加载QWebEnginer时，继承QApplication(唯一原因，就是为了overload notify),可能导致程序崩溃（原因可能是，谷歌浏览器内核，使用多线程加载GUI）。
2. 如果想要监听全局事件，在顶层父类中重载 bool event(QEvent*),是非常好的选择。
3. Qt有事件过滤器机制，这是比上两个稍微轻量的事件机制。Qt的事件传递机制是先发向notify->event->各个子类的详细的事件（move,show,wheel等等），如果子类不接受，发向上一层的父类。事件过滤器是，父类负责接收子类的事件，事件传递顺序变为 notify->event->事件过滤器->子类->父类。
4. 最常使用的是，像mousePressEvent,mouseDoubleClickEvent等等，直接在widget类中重载。