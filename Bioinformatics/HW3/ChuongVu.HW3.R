#Set my working directory
setwd("D:/ChuongStuff/Bio/HW3")

#Check the directory
getwd()

#Read data
data <- read.csv("data.csv", header=TRUE)

# Define variables with it row name based on the amino acids
d <- mydata[, -1]
rownames(d) <- data[, 1]

# Descriptive statistics
summary(d)


#Get mean value
meandata <- ddply(data, .(),numcolwise(mean))
meandata <- meandata[2:9]
rownames(meandata)[1] <- "Mean"
meandata[,-1] <- round(meandata[,-1], 2)

#Get Std.Dev
sddata <- ddply(data, .(), numcolwise(sd))
sddata[,-1] <- round(sddata[,-1], 2)
sddata <- sddata[2:9]
rownames(sddata)[1] <- "Std.Dev"

#Get Variance value
vardata <- ddply(data, .(), numcolwise(var))
vardata[,-1] <- round(vardata[,-1], 2)
vardata <- vardata[2:9]
rownames(vardata)[1] <- "Variance"

# this generate the correlation coefficient matrix
r = cor(d) 
r <- round(r, 2)

# Principal component analysis
pca1 <- princomp(d, scores=TRUE, cor=TRUE)
summary(pca1)



# Loadings of Principal components
loadings(pca1)

#Get eigenvalues 
library("factoextra")
eig.val <- get_eigenvalue(d.pca)
eig.val


#Use to graph a scree plot
fviz_screeplot(d.pca, ncp=10, choice="eigenvalue")

#Create Variables factors graph
fviz_pca_var(d.pca, col.var="contrib") + scale_color_gradient2(low="gray", mid="blue", high="red", midpoint=55) + theme_minimal()


#principal component analysis graph based on two largest components
plot(ind.coord[,1], ind.coord[,2], pch = 19, xlab="First Component", ylab="Second Component")
abline(h=0, v=0, lty=2)
text(ind.coord[,1], ind.coord[,2], labels=rownames(ind.coord), cex = 0.7, pos = 3)


