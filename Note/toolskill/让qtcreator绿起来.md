ʹ��qtcreator��ʱ��Ĭ�ϵİ������汳��ɫ�ǰ�ɫ�ģ��е���ۣ�Ϊ�˿��Կ������һ�㣬�����ĳ���ɫ����ͼЧ����

![](../../image/greenqtcreator.PNG)

QtCreator����������û���ṩ�ı�����ĵ�����ɫ�Ĺ��ܣ����ǿ���ͨ������������QtCreator����ͬʱ���ݲ�������������Щ����ʹ��Qt ��stylesheet,����ʮ�����Ķ���,�����������õȵȡ���

1. ��windows��ʹ��powershell,�������ñ�����
```pwsh
PS C:\> $profile #�鿴profile�ĵ�ַ�����û�У����½�һ����
PS C:\> New-Item -Type file -Force $profile
```
2. �༭profile�ļ�
```
function qt {
	 E:\Qt\Tools\QtCreator\bin\qtcreator.exe --stylesheet E:\Qt\qtcreatorstyle.txt
}
```
����·����һ����Qtcreator.exe��·����һ�����Զ����qss��·������qtcreatorstyle.txt������ȫ��qss���﷨��

```css
QPlainTextEdit
{
background-color: rgb(199, 237, 204);
}
QTextEdit
{
background-color: rgb(199, 237, 204);
}
```
3. Ȼ������powershell�Ϳ��Լ��� qt������QtCreator�ˡ�
4. ʹ�������л���ʮ�ַ���ģ������Ȼ��ʹ��˫��ͼ��ķ�ʽ��QtCreator,�Ͳ���Ҫ����������powershell�ˣ�ֱ������QtCreator�Ŀ�ݷ�ʽ�Ϳ����ˡ�


![](../../image/qtcreatorlink.PNG)