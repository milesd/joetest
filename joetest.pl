#!/usr/bin/perl

# To show you the advantages of the Perl programming language, we have rewritten this program:

#!/usr/local/bin/perl
#
# joetest
#
# while (($name,$passwd) = getpwent) {
#     print "$name is a joe\n" if (crypt($name,$passwd) eq $passwd);
# }

To further demonstrate the power of Perl, consider the following script, which only runs under Perl5:

#!/usr/local/bin/perl
#
# super joetest
#
while (($name,$passwd) = getpwent) {
		print "$name has no password\n" if !$passwd;
		print "$name is a joe\n" if (crypt($name,$passwd) eq $passwd);
		print "$name is a JOE\n" if (crypt(uc($name), $passwd) eq $passwd);
		print "$name is a Joe\n" if (crypt(ucfirst($name), $passwd) 
			eq $passwd);
		print "$name is a eoj\n" if (crypt(scalar reverse $name, $passwd)
			eq $passwd);
}