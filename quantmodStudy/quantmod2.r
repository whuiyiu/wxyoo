####start work
require("zoo")
require("Defaults")
require("xts")
require("quantmod")

####download all data of Apple, Microsoft, Ocrala and Google
myenv<-new.env()
getSymbols(c("AAPL","MSFT","ORCL","GOOG"),env=myenv,scr="yahoo")
ls(envir=myenv)
####sum the volumes of Apple (from 2013.1 to 2013.10)
getSymbols("AAPL",env=myenv,scr="yahoo",from="2013-01-01",to="2013-10-31")
months=to.monthly(get("AAPL",envir=myenv))
months
sum(months[1:10,5])

####找出AAPL暴涨或暴跌的时间点
##找出AAPL开盘价或收盘价比前一天涨跌幅度超过2%的时间点
AAPL.Cl<-Delt(Cl(get("AAPL",envir=myenv)),type=("arithmetic"))
AAPL.Cl[which(abs(AAPL.Cl)>0.02),]
plot(AAPL.Cl)

####计算收益率
getSymbols("AAPL",src="yahoo",from="2013-10-01",to="2013-10-30")
##daily
periodReturn(AAPL,period="daily")
periodReturn(AAPL,period="daily",subset="2013-10-01::2013-10-10")
periodReturn(AAPL,period="daily",type="arithmetic")
periodReturn(AAPL,period="daily",type="log")
dailyReturn(AAPL)
##全收益率
allReturns(AAPL)

####画图
chartSeries(AAPL)
chartSeries(AAPL,theme="white")
chartSeries(AAPL,name="AAPL CHART",subset="2013-10-01::2013-10-23")
chartSeries(AAPL,name="AAPL CHART",type="bars")
chartSeries(AAPL,name="AAPL CHART",type="line")
chartSeries(AAPL,name="AAPL CHART",type="candlesticks")

##barChart()   ##同chartSeries(AAPL,type="bars")
barChart(AAPL)  
barChart(AAPL,theme="white",subset="2012-12::2013")
##用last/first作时间段
barChart(AAPL,subset="last 10 weeks")
barChart(AAPL,subset="first 10 weeks")
barChart(AAPL,subset="first 10 weeks",bar.type="ohlc")
barChart(AAPL,subset="first 10 weeks",bar.type="hlc")

##candleChart()   ##同chartSeries(AAPL)
candleChart(AAPL,theme="white",subset="2013-10-05::2013-10-30")



##在已画过的图上修改
reChart(type="bars",subset="2013-10-05::2013-10-29", show.grid=TRUE)


