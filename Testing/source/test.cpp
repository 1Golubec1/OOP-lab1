#include <iostream>
#include "../../Student/header/struct_func.h"
#include "../../Convert/header/funcs_convert.h"
#include <format>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>


TEST_CASE("TEST_CONVERT_STRING"){
    Student student = stude::init_student("Ivan", "B23-513", 3.8), student2 = cnv::convert("student.name=Ivan\nstudent.group=B23-513\nstudent.grade=3.8\n");
    SECTION("CHECK_CORRECT_INPUT"){

        CHECK(stude::compar_students(student, student2) == true);

        student2 =cnv::convert("student.name=Ivan\nstudent.group=B23-513\nstudent.grade=3.08\n");

        CHECK(stude::compar_students(student, student2) == false);
    }

    student2 = {};

    SECTION("CHECK_INCORRET_INPUT"){
        CHECK_THROWS(student2 = cnv::convert("student.name Ivan\nstudent.group=B23-513\nstudent.grade=3.8\n")); 

        CHECK_THROWS(student2 = cnv::convert("student.name Ivan\nstudent.group=B23-513\nstudent.grade=nume\n"));

        CHECK_THROWS(student2 = cnv::convert(""));

        CHECK_THROWS(student2 = cnv::convert("student.name=Ivan\nstudent.group=B23-513\nstudent.grade=3.08"));

        CHECK_THROWS(student2 = cnv::convert("student.name=Ivan\nstudent.group=B23-513\nstudent.grade=nume\n"));

        CHECK_THROWS(student2 = cnv::convert("student.name=2141\nstudent.group=B23-513\nstudent.grade=3.08"));

        CHECK_THROWS(student2 = cnv::convert("name=Ivan\nstudent.group=B23-513\nstudent.grade=3.08\n"));

        CHECK_THROWS(student2 = cnv::convert("student.name=Ivan\ngroup=B23-513\nstudent.grade=3.08\n"));

        CHECK_THROWS(student2 = cnv::convert("student.name=Ivan\nstudent.group=ppp\nstudent.grade=3.08\n"));

        CHECK_THROWS(student2 = cnv::convert("student.name=Ivan\nstudent.group=B23-513\nstudent.grade=3.8\n info..."));

        CHECK_THROWS(student2 = cnv::convert("student.name=Ivan\nstudent.group=23513\nstudent.grade=3.8\n"));
    }

}

TEST_CASE("TEST_CONVERT_STRUCT"){
    Student student = stude::init_student("Ivan", "B23-513", 3.8);
    SECTION("CHECK_CORRECT_INPUT"){
        CHECK(cnv::convert(student) == "student.name=Ivan\nstudent.group=B23-513\nstudent.grade=3.8\n");
    }

}
