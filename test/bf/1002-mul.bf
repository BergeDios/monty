,>,<

#convert from ascii cell 1 and 2
------------------------------------------------
>------------------------------------------------
<

#multiply

[
  > #go to cell 2
    [ #new loop
       ->+>+<< #fill 3 and 4
    ] #until cell 2 reaches 0
     >> #cell 4
    [
      -<<+>> #refill 2
    ]
     <<<-
]
>> #convert to ascii cell 3
++++++++++++++++++++++++++++++++++++++++++++++++
. #output cell3
