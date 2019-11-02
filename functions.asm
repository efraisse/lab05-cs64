# xSpim Memory Demo Program

#  Data Area
.data

space:
    .asciiz " "

newline:
    .asciiz "\n"

dispArray:
    .asciiz "\nCurrent Array:\n"

convention:
    .asciiz "\nConvention Check\n"

myArray:
	.word 0 33 123 -66 332 -1 -223 453 9 45 -78 -14  

#Text Area (i.e. instructions)
.text

main:
    ori     $v0, $0, 4          
    la      $a0, dispArray 
    syscall

    ori     $s1, $0, 12
    la      $s0, myArray

    add     $a1, $0, $s1
    add     $a0, $0, $s0
 
    jal     DispArray

    ori     $s2, $0, 0
    ori     $s3, $0, 0
    ori     $s4, $0, 0
    ori     $s5, $0, 0
    ori     $s6, $0, 0
    ori     $s7, $0, 0
    
    add     $a1, $0, $s1
    add     $a0, $0, $s0

    jal     PrintReverse

    add     $s1, $s1, $s2
    add     $s1, $s1, $s3
    add     $s1, $s1, $s4
    add     $s1, $s1, $s5
    add     $s1, $s1, $s6
    add     $s1, $s1, $s7

    add     $a1, $0, $s1
    add     $a0, $0, $s0
    jal     DispArray

    j       Exit

DispArray:
    addi    $t0, $0, 0 
    add     $t1, $0, $a0

dispLoop:
    beq     $t0, $a1, dispend
    sll     $t2, $t0, 2
    add     $t3, $t1, $t2
    lw      $t4, 0($t3)

    ori     $v0, $0, 1
    add     $a0, $0, $t4
    syscall

    ori     $v0, $0, 4
    la      $a0, space
    syscall

    addi    $t0, $t0, 1
    j       dispLoop    

dispend:
    ori     $v0, $0, 4
    la      $a0, newline
    syscall
    jr      $ra 

ConventionCheck:
    addi    $t0, $0, -1
    addi    $t1, $0, -1
    addi    $t2, $0, -1
    addi    $t3, $0, -1
    addi    $t4, $0, -1
    addi    $t5, $0, -1
    addi    $t6, $0, -1
    addi    $t7, $0, -1
    ori     $v0, $0, 4
    la      $a0, convention
    syscall
    addi $v0, $zero, -1
    addi $v1, $zero, -1
    addi $a0, $zero, -1
    addi $a1, $zero, -1
    addi $a2, $zero, -1
    addi $a3, $zero, -1
    addi $k0, $zero, -1
    addi $k1, $zero, -1
    jr      $ra
    
Exit:
    ori     $v0, $0, 10
    syscall

# COPYFROMHERE - DO NOT REMOVE THIS LINE

PrintReverse:
    #TODO: write your code here, $a0 stores the address of the array, $a1 stores the length of the array
    li $t0, 0 #will be my counter for the loop
    add $t1, $t1, $a0 #get the address of the array since the value of a0 is the address of the array

    li $t7, 4
    li $t6, 0 #don't need this, this is for better understanding
    add $t6, $t6, $a1
    mult $t6, $t7
    mflo $t6 # t6 now contains the length of the array multiplied by 4
    sub $t6, $t6, $t7 #subtract 4 to get an accurate address of the last element
    sub $t1, $t1, $t6 #subtract t6 from the address of the array to start at the last element in the array

    j loopBack

loopBack:
    sll $t2, $t0, 2 #shift t0 by 4 to get the next address in the array
    add $t3, $t1, $t2 #add the address of the array to the shift to get the next element
    lw $t4, 0($t3) #load load the element of the array from memory

    li $v0, 1 #print out the element
    move $a2, $t4
    syscall
    jal ConventionCheck #call convention check like requested from the lab instructions

    add $t0, $t0, 1 #add 1 to the counter for my next shift in the array

    beq, $a1, $t0, exitLoop #if the counter is equal to the length of the array exit the program
    j loopBack #if not, loop again

exitLoop:
    jr $ra












