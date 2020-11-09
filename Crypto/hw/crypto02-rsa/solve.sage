from Crypto.Util.number import *
from gmpy2 import *

n = 22001778874542774315484392481115711539281104740723517828461360611903057304469869336789715900703500619163822273767393143914615001907123143200486464636351989898613180095341102875678204218769723325121832871221496816486100959384589443689594053640486953989205859492780929786509801664036223045197702752965199575588498118481259145703054094713019549136875163271600746675338534685099132138833920166786918380439074398183268612427028138632848870032333985485970488955991639327
c = 1067382668222320523824132555613324239857438151855225316282176402453660987952614935478188752664288189856467574123997124118639803436040589761488611318906877644244524931837804614243835412551576647161461088877884786181205274671088951504353502973964810690277238868854693198170257109413583371510824777614377906808757366142801309478368968340750993831416162099183649651151826983793949933939474873893278527484810417812120138131555544749220438456366110721231219155629863865
e = 65537
# n = p * q1 * q2 = p(2p+x)(6p+3x+y) = 12p^3 + 12p^2x + 2p^2y + 3px^2 + pxy
#                                    = 12p^3 + (12x+2y)p^2 + (3x^2+xy)p
#                                     > 12p^3

'''find p'''
p_est = next_prime(int(pow(n//12,1/3)))
q1 = next_prime(2 * p_est)
q2 = next_prime(3 *q1)
if (n <= p_est*q1*q2):
    for p in range(p_est, 0, -1):
        if (is_prime(p)):
            q1 = next_prime(2 * p)
            q2 = next_prime(3 *q1)
            if (p*q1*q2 == n):
                print(f'p is {p}')
                break
else:
    while(True):
        p = next_prime(p_est)
        q1 = next_prime(2 * p)
        q2 = next_prime(3 *q1)
        if (p*q1*q2 == n):
            print(f'p is {p}')
            break
    

'''calculate d'''
phi_n = (p-1) * (q1-1) * (q2-1)
d = inverse(e, phi_n)

'''decrypt c'''
m = pow(c, d, n)
print(f'm is {long_to_bytes(m)}')