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

####计算变化率,tpye is type of difference,缺省为arithmetic
##计算AAPL的开市价的变化率
Delt(Op(myenvironment$AAPL),type=c("arithmetic"))
Delt(Op(myenvironment$AAPL),type=c("log"))
##计算AAPL每天开市价相对于收市价的变化率
Delt(Op(myenvironment$AAPL),Cl(myenvironment$AAPL))
####其他用法
OpCl(myenvironment$AAPL) ##即Delt(Op(myenvironment$AAPL),Cl(myenvironment$AAPL))
ClCl(myenvironment$AAPL) ##即Delt(Cl(myenvironment$AAPL))

####从AAPL中提取前k行或后k行数据
first(myenvironment$AAPL,5)
last(myenvironment$AAPL,5)

####周汇总，月汇总
to.weekly(myenvironment$AAPL)
to.monthly(myenvironment$AAPL)

####从oanda上获取HKD/CNY汇率，保存到myenvironment
getFX("HKD/CNY", from = "2014-07-01",env = myenvironment)
####取出获取的汇率，变量名为“HKDCNY”
get("HKDCNY",envir = myenvironment)

####从GoogleFinance上下载财务报表,verbose=TURE显示下载细节
getFinancials("AAPL",verbose=TRUE)   ##[1] "AAPL.f"  save in AAPL.f
####查看财务报表
##viewFinancials(x, type=c('BS','IS','CF'), period=c('A','Q'),subset = NULL)
##IS(收入报表), BS(资产负债表), CF(资金流); A(年度), Q(季度)
viewFinancials(AAPL.f)
viewFinancials(AAPL.f, c("CF","IS","BS"),"Q")

####从Yahoo Finance上下载股息数据
getDividends("AAPL",env=myenvironment,from="2014-01-01",to="2014-06-30",verbose=TRUE)

