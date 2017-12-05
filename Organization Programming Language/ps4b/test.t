#!/usr/bin/perl
use 5.10.0;
use warnings FATAL => 'all';

use File::Temp;
use File::Copy;
use IO::Handle;

sub scm_eval {
    my ($cmdline) = @_;
    my $tmpcmd = File::Temp->new;
    $tmpcmd->say($cmdline);
    my $tmpcode = File::Temp->new;
    copy("ps.rkt", $tmpcode) or die "Copy failed: $!";
    open(my $fh, '>>', $tmpcode);
    $fh->say('
(define-namespace-anchor bottlenose-nsa)
(define bottlenose-ns (namespace-anchor->namespace bottlenose-nsa))
(eval (call-with-input-string (vector-ref (current-command-line-arguments) 0) read) bottlenose-ns)');
    my $result = `racket $tmpcode '(load "$tmpcmd")'`;
    chomp $result;
#    print "answer was ", $result, " ";
    return $result;
}

sub scm_equal {
    my ($e0, $e1) = @_;
    my $tmp = File::Temp->new;
    $tmp->say("(equal? $e0 $e1)");
    my $result = `racket -e '(load "$tmp")'`;
    chomp $result;
    return $result eq "#t";
}

sub scm_equal_sign {
    my ($e0, $e1) = @_;
    my $tmp = File::Temp->new;
    $tmp->say("(= $e0 $e1)");
    my $result = `racket -e '(load "$tmp")'`;
    chomp $result;
    return $result eq "#t";
}

use Test::Simple tests => 10;

# using procedure closures to implement cons cells
ok(scm_equal(scm_eval("(my-car (my-cons 'foo 'bar))"), "'foo"), "my-car symbol");
ok(scm_equal(scm_eval("(my-cdr (my-cons 'foo 'bar))"), "'bar"), "my-cdr symbol");
ok(scm_equal_sign(scm_eval("(my-car (my-cons (+ 1 2) (+ 3 4)))"), 3), "my-car number");
ok(scm_equal_sign(scm_eval("(my-cdr (my-cons (+ 1 2) (+ 3 4)))"), 7), "my-cdr number");
ok(scm_equal(scm_eval(
"(begin (define cons1 (my-cons 'bar '()))".
"       (define cons2 (my-cons 'foo cons1))".
"       (my-car (my-cdr cons2)))"
), "'bar"), "nested cons cells");
ok(scm_equal(scm_eval(
"(begin (define cons3 (my-cons 'bar '()))".
"       (define cons4 (my-cons 'foo cons3))".
"       (define cons5 (my-cons 'cat cons4))".
"       (my-car (my-cdr (my-cdr cons5))))"
), "'bar"), "double nested cons cells");
ok(scm_equal(scm_eval("env-diagram"), "#t"), "env diagram for (define foo (my-cons 3 4))");
ok(scm_equal(scm_eval("env-diagram"), "#t"), "env diagram for (define foo (my-cons 3 4))");
ok(scm_equal(scm_eval("env-diagram"), "#t"), "env diagram for (define foo (my-cons 3 4))");
ok(scm_equal(scm_eval("env-diagram"), "#t"), "env diagram for (define foo (my-cons 3 4))");


