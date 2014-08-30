__author__ = 'Vishal'


class RunLengthEncoding:
    def encode_string(self, compress_string):
        cnt = 0
        l = []
        for i, c in enumerate(compress_string):
            if i != 0:
                if compress_string[i-1] == compress_string[i]:
                    cnt += 1
                else:
                    l.append(str(cnt+1))
                    l.append(compress_string[i-1])
                    cnt = 0
        finalstring = "".join(l)
        print(finalstring)

intstance = RunLengthEncoding()
intstance.encode_string("aaaaBBBBccccDDDDeeeef")