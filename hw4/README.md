Part 1 


In this part, you will build an array with some modifications with the given array as input parameter and return it on output
array parameter. We want you to write a function (addPadding) that takes an array and adds padding (additional array
elements) to left and right side of this array. Padding operation is explained below. addPadding function also takes array
size (integer), padding width (integer, number of elements that you will add both sides) and padding method (function
pointer) as argument. You must implement three different padding methods.



Part 2 50pts


In the second part, you will make a convolution operation over a given array. This operation has two components: First
component is an input array and second component is a kernel array. The relationship between these two components are
shown in figure 1. Kernel array moves on the input array in each iteration and calculates one array element for the output
array.
one element = K 1 ∗ A i + K 2 ∗ A i+1 + ⋯ + K j ∗ A i+j−1
If you look at the output array in the figure 1, you can see that the size of the array shrinks after convolution operation. To
prevent that, you will add some padding to the inputArray and get an output array with the same size. You can use the
function that you wrote in the part 1 for the padding operation.
Another parameter, stride that effects the step for the convolution operation. Stride is the amount of kernel movement for
each iteration. Stride is 1 for the figure 1. If stride is 2, then you will move the kernel not one element, but 2 elements for
one iteration. If there is no error return 0, otherwise return -1.
