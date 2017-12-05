# use to remove all objects
rm(list=ls(all=TRUE))

#Set my working directory
setwd("D:/ChuongStuff/Bio/HW6")

#Check the directory
getwd()

##########################################
# Perform setosa and vericolor

# Read and Store data
iris.set.vir = read.table("Iris-set.ver.txt")

#Loading library
library(quadprog)
library(e1071)

train <- iris.set.vir
train$y <-ifelse(train[,5]=="setosa", 1, -1)

# order the training data labeling to avoid oddities with 
# see http://www.csie.ntu.edu.tw/~cjlin/libsvm/faq.html#f430
train <- train[order(train$y, decreasing=TRUE),]

# set the problem data and parameters
X <- as.matrix(train[,c("Petal.Length", "Petal.Width")])
y <- as.matrix(train$y)
n <- dim(X)[1]


eps <- 5e-4

# build the system matrices
Q <- sapply(1:n, function(i) y[i]*t(X)[,i])
D <- t(Q)%*%Q
d <- matrix(1, nrow=n)
b0 <- rbind( matrix(0, nrow=1, ncol=1) , matrix(0, nrow=n, ncol=1))
A <- t(rbind(matrix(y, nrow=1, ncol=n), diag(nrow=n)))


# call the QP solver:
sol <- solve.QP(D +eps*diag(n), d, A, b0, meq=0, factorized=FALSE)
qpsol <- matrix(sol$solution, nrow=n)


####################################################################################################################
# This solver is implemented to solve a soft-margin problem.  If we choose C very large, 
# then the margins will be very small and we'll approach the hard-margin classification problem that we solved above
####################################################################################################################
C <- 1e5     # Huge value forces hard margin problem
sv <- svm(Species~Petal.Length+Petal.Width, data=train, kernel="linear", scale=FALSE, type="C-classification", cost=C)


# Now we get the slope and intercept
W <- rowSums(sapply(1:length(sv$coefs), function(i) sv$coefs[i]*sv$SV[i,]))
svmline = c(sv$rho/W[2], -W[1]/W[2])


# extract and plot the decision boundary from the results of each solver.
# build the support vectors, slopes, and intercepts
findLine <- function(a, y, X){
  nonzero <-  abs(a) > 1e-5
  W <- rowSums(sapply(which(nonzero), function(i) a[i]*y[i]*X[i,]))
  b <- mean(sapply(which(nonzero), function(i) X[i,]%*%W- y[i]))
  slope <- -W[1]/W[2]
  intercept <- b/W[2]
  return(c(intercept,slope))
}
qpline <- findLine( qpsol, y, X)


# plot the results
library(ggplot2)
plt <- ggplot(train, aes(x=Petal.Length, y=Petal.Width)) + 
  ggtitle("Solving the SVM QP for Setosa and Vericolor") +
  geom_point(aes(fill=factor(y)), size=3, pch=21) +
  geom_abline(intercept=qpline[1], slope=qpline[2], size=1, aes(color="quadprog"), show.legend=TRUE) +
  geom_abline(intercept=svmline[1], slope=svmline[2], size=1, aes(color="svm"))+
  scale_fill_manual(values=c("red","blue"), guide='none')+
  scale_color_manual(values=c("green", "yellow", "black"))+
  theme(legend.position="bottom", legend.title=element_blank())
print(plt)

# print the results
print(sprintf("quadprog number of nonzeros: %d", sum(abs(qpsol)>1e-7)))
print(sprintf("svm number of nonzeros: %d", length(sv$coefs)))
print(sprintf("Quadprog: Intercept: %f    Slope: %f", qpline[1], qpline[2]))
print(sprintf("svm: Intercept: %f    Slope: %f", svmline[1], svmline[2]))





##########################################
# Perform vericolor and virginica
# Similar with setosa and vericolor but different values

## Reset program ##
# use to remove all objects
rm(list=ls(all=TRUE))

#Set my working directory
setwd("D:/ChuongStuff/Bio/HW6")

#Check the directory
getwd()

# Read and Store data
iris.ver.vir = read.table("Iris-ver.vir.txt")

#Loading library
library(quadprog)
library(e1071)

train <- iris.ver.vir
train$y <-ifelse(train[,5]=="versicolor", 1, -1)

# order the training data labeling to avoid oddities with 
# see http://www.csie.ntu.edu.tw/~cjlin/libsvm/faq.html#f430
train <- train[order(train$y, decreasing=TRUE),]

# set the problem data and parameters
X <- as.matrix(train[,c("Petal.Length", "Petal.Width")])
y <- as.matrix(train$y)
n <- dim(X)[1]

eps <- 5e-4

# build the system matrices
Q <- sapply(1:n, function(i) y[i]*t(X)[,i])
D <- t(Q)%*%Q
d <- matrix(1, nrow=n)
b0 <- rbind( matrix(0, nrow=1, ncol=1) , matrix(0, nrow=n, ncol=1))
A <- t(rbind(matrix(y, nrow=1, ncol=n), diag(nrow=n)))


# call the QP solver:
sol <- solve.QP(D +eps*diag(n), d, A, b0, meq=0, factorized=FALSE)
qpsol <- matrix(sol$solution, nrow=n)


####################################################################################################################
# This solver is implemented to solve a soft-margin problem.  If we choose C very large, 
# then the margins will be very small and we'll approach the hard-margin classification problem that we solved above
####################################################################################################################
C <- 1e5     # Huge value forces hard margin problem
sv <- svm(Species~Petal.Length+Petal.Width, data=train, kernel="linear", scale=FALSE, type="C-classification", cost=C)


# Now we get the slope and intercept
W <- rowSums(sapply(1:length(sv$coefs), function(i) sv$coefs[i]*sv$SV[i,]))
svmline = c(sv$rho/W[2], -W[1]/W[2])


# extract and plot the decision boundary from the results of each solver.
# build the support vectors, slopes, and intercepts
findLine <- function(a, y, X){
  nonzero <-  abs(a) > 1e-5
  W <- rowSums(sapply(which(nonzero), function(i) a[i]*y[i]*X[i,]))
  b <- mean(sapply(which(nonzero), function(i) X[i,]%*%W- y[i]))
  slope <- -W[1]/W[2]
  intercept <- b/W[2]
  return(c(intercept,slope))
}
qpline <- findLine( qpsol, y, X)


# plot the results
library(ggplot2)
plt <- ggplot(train, aes(x=Petal.Length, y=Petal.Width)) + 
  ggtitle("Solving the SVM QP for Vericolor and Virginica") +
  geom_point(aes(fill=factor(y)), size=3, pch=21) +
  geom_abline(intercept=qpline[1], slope=qpline[2], size=1, aes(color="quadprog"), show.legend=TRUE) +
  geom_abline(intercept=svmline[1], slope=svmline[2], size=1, aes(color="svm"))+
  scale_fill_manual(values=c("red","blue"), guide='none')+
  scale_color_manual(values=c("green", "yellow", "black"))+
  theme(legend.position="bottom", legend.title=element_blank())
print(plt)

# print the results
print(sprintf("quadprog number of nonzeros: %d", sum(abs(qpsol)>1e-7)))
print(sprintf("svm number of nonzeros: %d", length(sv$coefs)))
print(sprintf("Quadprog: Intercept: %f    Slope: %f", qpline[1], qpline[2]))
print(sprintf("svm: Intercept: %f    Slope: %f", svmline[1], svmline[2]))


##########################################
# Perform full size of iris

## Reset program ##
# use to remove all objects
rm(list=ls(all=TRUE))

#Set my working directory
setwd("D:/ChuongStuff/Bio/HW6")

#Check the directory
getwd()

#Loading library
library(quadprog)
library(e1071)

train <- iris
train$y <-ifelse(train[,5]=="setosa", 1, -1)

# order the training data labeling to avoid oddities with 
# see http://www.csie.ntu.edu.tw/~cjlin/libsvm/faq.html#f430
train <- train[order(train$y, decreasing=TRUE),]

# set the problem data and parameters
X <- as.matrix(train[,c("Petal.Length", "Petal.Width")])
y <- as.matrix(train$y)
n <- dim(X)[1]

eps <- 5e-4

# build the system matrices
Q <- sapply(1:n, function(i) y[i]*t(X)[,i])
D <- t(Q)%*%Q
d <- matrix(1, nrow=n)
b0 <- rbind( matrix(0, nrow=1, ncol=1) , matrix(0, nrow=n, ncol=1))
A <- t(rbind(matrix(y, nrow=1, ncol=n), diag(nrow=n)))


# call the QP solver:
sol <- solve.QP(D +eps*diag(n), d, A, b0, meq=0, factorized=FALSE)
qpsol <- matrix(sol$solution, nrow=n)


####################################################################################################################
# This solver is implemented to solve a soft-margin problem.  If we choose C very large, 
# then the margins will be very small and we'll approach the hard-margin classification problem that we solved above
####################################################################################################################
C <- 1e5     # Huge value forces hard margin problem
sv <- svm(y~Petal.Length+Petal.Width, data=train, kernel="linear", scale=FALSE, type="C-classification", cost=C)


# Now we get the slope and intercept
W <- rowSums(sapply(1:length(sv$coefs), function(i) sv$coefs[i]*sv$SV[i,]))
svmline = c(sv$rho/W[2], -W[1]/W[2])


# extract and plot the decision boundary from the results of each solver.
# build the support vectors, slopes, and intercepts
findLine <- function(a, y, X){
  nonzero <-  abs(a) > 1e-5
  W <- rowSums(sapply(which(nonzero), function(i) a[i]*y[i]*X[i,]))
  b <- mean(sapply(which(nonzero), function(i) X[i,]%*%W- y[i]))
  slope <- -W[1]/W[2]
  intercept <- b/W[2]
  return(c(intercept,slope))
}
qpline <- findLine( qpsol, y, X)


# plot the results
library(ggplot2)
plt <- ggplot(train, aes(x=Petal.Length, y=Petal.Width)) + 
  ggtitle("Solving the SVM QP") +
  geom_point(aes(fill=factor(y)), size=3, pch=21) +
  geom_abline(intercept=qpline[1], slope=qpline[2], size=1, aes(color="quadprog"), show.legend=TRUE) +
  geom_abline(intercept=svmline[1], slope=svmline[2], size=1, aes(color="svm"))+
  scale_fill_manual(values=c("red","blue"), guide='none')+
  scale_color_manual(values=c("green", "yellow", "black"))+
  theme(legend.position="bottom", legend.title=element_blank())
print(plt)

# print the results
print(sprintf("quadprog number of nonzeros: %d", sum(abs(qpsol)>1e-7)))
print(sprintf("svm number of nonzeros: %d", length(sv$coefs)))
print(sprintf("Quadprog: Intercept: %f    Slope: %f", qpline[1], qpline[2]))
print(sprintf("svm: Intercept: %f    Slope: %f", svmline[1], svmline[2]))







