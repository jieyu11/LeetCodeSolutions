class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        #numerator = -2147483648
        #denominator = 1
        sign = ""
        if numerator // denominator < 0:
            sign = "-"
            
        numerator = abs(numerator)
        denominator = abs(denominator)
        
        a = numerator // denominator
        b = numerator % denominator
        if b==0 :
            return ( sign + str(a) )
        
        # remainder
        rem = {}
        idx = 0
        bs = ""
        while (b not in rem):
            rem[b] = idx
            b = b * 10;            
            bs += str( b // denominator ) 
            b = b % denominator
            if b == 0:
                break
            idx += 1
        #print b
        #print rem
        
        if b in rem:
            idxsta = rem[b]
            bs = bs[:idxsta] + '(' + bs[idxsta:] + ')'
        
        return (sign + str(a)+'.'+bs)

