# Get data from the library
dim(iris)

#Display the name of data header
names(iris)

#data's structure
str(iris)

#data's attributes
attributes(iris)


# get correlation matrix
cor(iris[1:4])

# get covariance matrix
cov(iris[1:4])

# calulate eigenvalues
covM <- cov(iris[1:4])
eig <- eigen(covM,symmetric=TRUE,only.values=FALSE)
c <- colnames(iris[1:4])
eig$values

rownames(eig$vectors) <- c(colnames(iris[1:4]))
eig$vectors

# get first component variation
eig$values[1]/sum(eig$values)

# get second component variation
sum(eig$values[1:2])/sum(eig$values)


irispca <- princomp(iris[1:4])
# Variance Explained
summary(irispca)

# Eigenvectors
irispca$loadings

# Coordinates of the data along PCs:
irispca$scores[1:10, ]

# Biplot graph
biplot(irispca, col = c("blue", "red"))

# get the minimum, maximum, mean, median, the first (25%) and the third (75%) quartiles. 
summary(iris[1:4])

# Consider orientaion of outlying observations:
iris[42, ]

iris[132, ]

#========================================
# THE K-MEAN CLUSTERING

iris2 <- iris
iris2$Species <- NULL
kmeans.result <- kmeans(iris2, 3)
(kmeans.result <- kmeans(iris2, 3))


table(iris$Species, kmeans.result$cluster)


# k-Means Clustering graph
plot(iris2[c("Sepal.Length", "Sepal.Width")], col = kmeans.result$cluster)


# plot cluster centers
points(kmeans.result$centers[,c("Sepal.Length", "Sepal.Width")], col = 1:3, pch = 8, cex = 2)

#========================================
# THE K-MEDOIDS CLUSTERING

library(fpc)
pamk.result <- pamk(iris2)
# number of clusters
pamk.result$nc


# check clustering against actual species
table(pamk.result$pamobject$clustering, iris$Species)

# 2 graphs per page
layout(matrix(c(1,2),1,2)) 
plot(pamk.result$pamobject)

# change back to one graph per page
layout(matrix(1)) 


# try pam() with k = 3
library(cluster)
pam.result <- pam(iris2, 3)
table(pam.result$clustering, iris$Species)

# 2 graphs per page
layout(matrix(c(1,2),1,2))
plot(pam.result)

# change back to one graph per page
layout(matrix(1))

#========================================
# HIERACHICAL CLUSTERING

idx <- sample(1:dim(iris)[1], 40)
irisSample <- iris[idx, ]
irisSample$Species <- NULL
hc <- hclust(dist(irisSample), method="ave")
plot(hc, hang = -1, labels=iris$Species[idx])

# cut tree into 3 clusters
rect.hclust(hc, k=3)
groups <- cutree(hc, k=3)



#========================================
# VARIABLE CLUSTERING WITH PCA

eig$vectors[, 1]

#First entry in each eigenvectors give coefficients for Variable 1:
eig$vectors[1,]

# Comparison with PCA and Correlation Matrix

irispca2 <- princomp(iris[1:4], cor = TRUE)
summary(irispca2)

irispca2$loadings


irispca2$scores[1:10, ]


plot(irispca2$scores[, 1], irispca2$scores[, 2], main = "Data Projected on First 2 Principal Components", xlab="FirstPrincipalComponent",ylab="SecondPrincipalComponent", col=c("red","green3","blue")[iris$Species])

biplot(irispca2)

#========================================
# PCA POINT CORRESPONDS

###pca - calculated for the first 4 columns of the data set that correspond to biometric measurements 
#("Sepal.Length" "Sepal.Width"  "Petal.Length" "Petal.Width")
data(iris)
dat <- as.matrix(iris[,-5])
pca <- prcomp(dat, retx=TRUE, center=TRUE, scale=TRUE)


###Create new data sets for each of the three species. 
#Biometric values are based on the distributions of the original data means
#and the covariances between these parameters. 
setosa.mean <- apply(iris[iris$Species=="setosa",-5], 2, mean)
setosa.cov <- cov(iris[iris$Species=="setosa",-5])

versicolor.mean <- apply(iris[iris$Species=="versicolor",-5], 2, mean)
versicolor.cov <- cov(iris[iris$Species=="versicolor",-5])

virginica.mean <- apply(iris[iris$Species=="virginica",-5], 2, mean)
virginica.cov <- cov(iris[iris$Species=="virginica",-5])


#Make new random data based on the calculated biometry info. each species
#The MASS package allows for the calculation of correlated/covarying random 
#numbers using this information.
library(MASS)
set.seed(1)
n <- 30
new.setosa <- mvrnorm(n, setosa.mean, setosa.cov)
new.versicolor <- mvrnorm(n, versicolor.mean, versicolor.cov)
new.virginica <- mvrnorm(n, virginica.mean, virginica.cov)


###Predict PCs by projecting the new data using the predict.prcomp function
pred.setosa <- predict(pca, new.setosa)
pred.versicolor <- predict(pca, new.versicolor)
pred.virginica <- predict(pca, new.virginica)


###Plot result
SPP <- iris$Species
COLOR <- c(2:4)
PCH <- c(1,16)

pc <- c(1,2)
plot(pca$x[,pc[1]], pca$x[,pc[2]], col=COLOR[SPP], cex=PCH[1], xlab=paste0("PC ", pc[1], " (", round(pca$sdev[pc[1]]/sum(pca$sdev)*100,0), "%)"), ylab=paste0("PC ", pc[2], " (", round(pca$sdev[pc[2]]/sum(pca$sdev)*100,0), "%)"))
points(pred.setosa[,pc[1]], pred.setosa[,pc[2]], col=COLOR[levels(SPP)=="setosa"], pch=PCH[2])
points(pred.versicolor[,pc[1]], pred.versicolor[,pc[2]], col=COLOR[levels(SPP)=="versicolor"], pch=PCH[2])
points(pred.virginica[,pc[1]], pred.virginica[,pc[2]], col=COLOR[levels(SPP)=="virginica"], pch=PCH[2])
legend("topright", legend=levels(iris$Species), col=COLOR, pch=17)
legend("topleft", legend=c("Original data", "New data"), col=1, pch=PCH)



# use to draw line between data (not really useful because so confuse to look at this)
segments(pca$x[,pc[1]], pca$x[,pc[2]], pred.setosa[,pc[1]], pred.setosa[,pc[2]], col="black")
segments(pca$x[,pc[1]], pca$x[,pc[2]], pred.versicolor[,pc[1]], pred.versicolor[,pc[2]], col="pink")
segments(pca$x[,pc[1]], pca$x[,pc[2]], pred.virginica[,pc[1]], pred.virginica[,pc[2]], col="cyan")





# use to remove all objects
rm(list=ls(all=TRUE))




























