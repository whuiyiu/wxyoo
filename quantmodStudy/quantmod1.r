####install quantmod packages
install.packages("zoo")
install.packages("Defaults")
install.packages("xts")
install.packages("quantmod")

####start work
require("zoo")
require("Defaults")
require("xts")
require("quantmod")
setwd("D:\\quantmod\\quantmod1")

####creat environment myenvironment
myenvironment <- new.env()
####collect AAPL data from yahoo and save to myenvironment
getSymbols("AAPL",env=myenvironment,src="yahoo",from ="2014-01-01",to="2014-06-30")
####list the variables in myenvironment
ls(envir=myenvironment)
####get(print) AAPL from myenvironment
get("AAPL",envir=myenvironment)
####check
is.OHLC(myenvironment$AAPL)
is.OHLCV(myenvironment$AAPL)
has.OHLC(myenvironment$AAPL)
has.Op(myenvironment$AAPL)
has.Hi(myenvironment$AAPL)
has.Vo(myenvironment$AAPL)
####select from AAPL
Op(myenvironment$AAPL)
OHLC(myenvironment$AAPL)
Vo(myenvironment$AAPL)
Ad(myenvironment$AAPL)

####����仯��,tpye is type of difference,ȱʡΪarithmetic
##����AAPL�Ŀ��м۵ı仯��
Delt(Op(myenvironment$AAPL),type=c("arithmetic"))
Delt(Op(myenvironment$AAPL),type=c("log"))
##����AAPLÿ�쿪�м���������м۵ı仯��
Delt(Op(myenvironment$AAPL),Cl(myenvironment$AAPL))
####�����÷�
OpCl(myenvironment$AAPL) ##��Delt(Op(myenvironment$AAPL),Cl(myenvironment$AAPL))
ClCl(myenvironment$AAPL) ##��Delt(Cl(myenvironment$AAPL))

####��AAPL����ȡǰk�л��k������
first(myenvironment$AAPL,5)
last(myenvironment$AAPL,5)

####�ܻ��ܣ��»���
to.weekly(myenvironment$AAPL)
to.monthly(myenvironment$AAPL)

####��oanda�ϻ�ȡHKD/CNY���ʣ����浽myenvironment
getFX("HKD/CNY", from = "2014-07-01",env = myenvironment)
####ȡ����ȡ�Ļ��ʣ�������Ϊ��HKDCNY��
get("HKDCNY",envir = myenvironment)

####��GoogleFinance�����ز��񱨱�,verbose=TURE��ʾ����ϸ��
getFinancials("AAPL",verbose=TRUE)   ##[1] "AAPL.f"  save in AAPL.f
####�鿴���񱨱�
##viewFinancials(x, type=c('BS','IS','CF'), period=c('A','Q'),subset = NULL)
##IS(���뱨��), BS(�ʲ���ծ��), CF(�ʽ���); A(���), Q(����)
viewFinancials(AAPL.f)
viewFinancials(AAPL.f, c("CF","IS","BS"),"Q")

####��Yahoo Finance�����ع�Ϣ����
getDividends("AAPL",env=myenvironment,from="2014-01-01",to="2014-06-30",verbose=TRUE)

